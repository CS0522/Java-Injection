%top{
#include <ctype.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include "../include/ognl-parser.h"
#include "../include/ognl.tab.h"
#include "../include/gramparse.h"
}

%{

#include "../include/pg-pos.h"
int backslash_quote = BACKSLASH_QUOTE_SAFE_ENCODING;
bool escape_string_warning = true;
bool standard_conforming_strings = true;
int token_count=0;

#define PG_KEYWORD(kwname, value, category, collabel) value,
const uint16 ScanKeywordTokens[] = {
#include "../include/kwlist.h"
};

#undef PG_KEYWORD
#define YYSTYPE core_YYSTYPE
#define SET_YYLLOC() (*(yylloc) = yytext - yyextra->scanbuf)
#define ADVANCE_YYLLOC(delta) ( *(yylloc) += (delta) )
#define PUSH_YYLLOC() (yyextra->save_yylloc = *(yylloc))
#define POP_YYLLOC() (*(yylloc) = yyextra->save_yylloc)

#define startlit() ( yyextra->literallen = 0 )
static void addlit(char *ytext, int yleng, core_yyscan_t yyscanner);
static void addlitchar(unsigned char ychar, core_yyscan_t yyscanner);
static char *litbufdup(core_yyscan_t yyscanner);
static unsigned char unescape_single_char(unsigned char c, core_yyscan_t yyscanner);
static int process_integer_literal(const char *token, YYSTYPE *lval);
static void addunicode(pg_wchar c, yyscan_t yyscanner);
void scanner_yyerror(const char *message, core_yyscan_t yyscanner);


static void check_string_escape_warning(unsigned char ychar, core_yyscan_t yyscanner);
static void check_escape_warning(core_yyscan_t yyscanner);

#define yyerror(msg) scanner_yyerror(msg, yyscanner)
%}

%option noyywrap nodefault yylineno case-insensitive reentrant
%option bison-bridge bison-locations
%option extra-type="struct core_yy_extra_type *"
%option header-file="ognl.lex.h"
%option prefix="core_yy"
%option noinput
%option nounput
%option noyyalloc
%option noyyrealloc
%option noyyfree
%option warn

%x xb
%x xc
%x xd
%x xh
%x xq
%x xqs
%x xe
%x xdolq
%x xui
%x xus
%x xeu
%x xsp

space                   [ \t\n\r\f]
horiz_space             [ \t\f]
newline                 [\n\r]
non_newline             [^\n\r]

comment                 ("--"{non_newline}*)

whitespace              ({space}+|{comment})

special_whitespace              ({space}+|{comment}{newline})
horiz_whitespace                ({horiz_space}|{comment})
whitespace_with_newline ({horiz_whitespace}*{newline}{special_whitespace}*)

quote                   '
/* If we see {quote} then {quotecontinue}, the quoted string continues */
quotecontinue   {whitespace_with_newline}{quote}

/*
 * {quotecontinuefail} is needed to avoid lexer backup when we fail to match
 * {quotecontinue}.  It might seem that this could just be {whitespace}*,
 * but if there's a dash after {whitespace_with_newline}, it must be consumed
 * to see if there's another dash --- which would start a {comment} and thus
 * allow continuation of the {quotecontinue} token.
 */
quotecontinuefail       {whitespace}*"-"?

/* Bit string
 * It is tempting to scan the string for only those characters
 * which are allowed. However, this leads to silently swallowed
 * characters if illegal characters are included in the string.
 * For example, if xbinside is [01] then B'ABCD' is interpreted
 * as a zero-length string, and the ABCD' is lost!
 * Better to pass the string forward and let the input routines
 * validate the contents.
 */
xbstart                 [bB]{quote}
xbinside                [^']*

/* Hexadecimal byte string */
xhstart                 [xX]{quote}
xhinside                [^']*

/* National character */
xnstart                 [nN]{quote}

/* Quoted string that allows backslash escapes */
xestart                 [eE]{quote}
xeinside                [^\\']+
xeescape                [\\][^0-7]
xeoctesc                [\\][0-7]{1,3}
xehexesc                [\\]x[0-9A-Fa-f]{1,2}
xeunicode               [\\](u[0-9A-Fa-f]{4}|U[0-9A-Fa-f]{8})
xeunicodefail   [\\](u[0-9A-Fa-f]{0,3}|U[0-9A-Fa-f]{0,7})

/* Extended quote
 * xqdouble implements embedded quote, ''''
 */
xqstart                 {quote}
xqdouble                {quote}{quote}
xqinside                [^']+

/* Double quote
 * Allows embedded spaces and other special characters into identifiers.
 */
dquote                  \"
xdstart                 {dquote}
xdstop                  {dquote}
xddouble                {dquote}{dquote}
xdinside                [^"]+

/* Quoted identifier with Unicode escapes */
xuistart                [uU]&{dquote}

/* Quoted string with Unicode escapes */
xusstart                [uU]&{quote}

/* error rule to avoid backup */
xufailed                [uU]&


/* INTEGER_LITERAL  DOUBLE_LITERAL*/
digit                          [0-9]
integer                        {digit}+
decimal                 (({digit}*\.{digit}+)|({digit}+\.{digit}*))
decimalfail             {digit}+\.\.

/*IDENTIFIER*/
ident_start             [A-Za-z\200-\377_\\]
ident_cont              [A-Za-z\200-\377_0-9\$]

identifier              {ident_start}{ident_cont}*

expression_start               "%{"
expression_end                 "}"

dot_dot                        \.\.

not_equal                      "!="
equal                          "=="
less_equal                     "<="
greater_equal                  ">="
and_and                        "&&"
or_or                          "||"

other                          .

%%

{whitespace}    {
                                        /* ignore */
                                }
{dot_dot}       {
                                        SET_YYLLOC();
                                        token_count+=1; return DOT_DOT;
                                }
{expression_start}      {
                                        SET_YYLLOC();
                                        token_count+=1; return EXPRESSION_START;
                                }
{expression_end}        {
                                        SET_YYLLOC();
                                        token_count+=1; return EXPRESSION_END;
                                }
{not_equal}     {
                                        SET_YYLLOC();
                                        token_count+=1; return NOT_EQUAL;
                                }
{equal}         {
                                        SET_YYLLOC();
                                        token_count+=1; return EQUAL;
                                }
{less_equal}    {
                                        SET_YYLLOC();
                                        token_count+=1; return LESS_EQUAL;
                                }
{greater_equal} {
                                        SET_YYLLOC();
                                        token_count+=1; return GREATER_EQUAL;
                                }
{and_and}       {
                                        SET_YYLLOC();
                                        token_count+=1; return AND_AND;
                                }
{or_or}         {
                                        SET_YYLLOC();
                                        token_count+=1; return OR_OR;
                                }
{xbstart}               {
                                        /* Binary bit type.
                                         * At some point we should simply pass the string
                                         * forward to the parser and label it there.
                                         * In the meantime, place a leading "b" on the string
                                         * to mark it for the input routine as a binary string.
                                         */
                                        SET_YYLLOC();
                                        BEGIN(xb);
                                        startlit();
                                        addlitchar('b', yyscanner);
                                }
<xh>{xhinside}  |
<xb>{xbinside}  {
                                        addlit(yytext, yyleng, yyscanner);
                                }
<xb><<EOF>>             { yyerror("unterminated bit string literal"); yyterminate();}

{xhstart}               {
                                        /* Hexadecimal bit type.
                                         * At some point we should simply pass the string
                                         * forward to the parser and label it there.
                                         * In the meantime, place a leading "x" on the string
                                         * to mark it for the input routine as a hex string.
                                         */
                                        SET_YYLLOC();
                                        BEGIN(xh);
                                        startlit();
                                        addlitchar('x', yyscanner);
                                }
<xh><<EOF>>             { yyerror("unterminated hexadecimal string literal"); yyterminate();}

{xnstart}               {
                                        /* National character.
                                         * We will pass this along as a normal character string,
                                         * but preceded with an internally-generated "NCHAR".
                                         */
                                        int             kwnum;

                                        SET_YYLLOC();
                                        yyless(1);      /* eat only 'n' this time */

                                        kwnum = ScanKeywordLookup("nchar",
                                                                                          yyextra->keywordlist)
;
                                        if (kwnum >= 0)
                                        {
                                                yylval->keyword = GetScanKeyword(kwnum,
                                                                                                                 yyextra->keywordlist);                                                                                                                                       token_count+=1; return yyextra->keyword_tokens[kwnum];
                                        }
                                        else
                                        {
                                                /* If NCHAR isn't a keyword, just return "n" */
                                                yylval->str = pstrdup("n");
                                                token_count+=1; return IDENT;
                                        }
                                }

{xqstart}               {
                                        yyextra->warn_on_first_escape = true;
                                        yyextra->saw_non_ascii = false;
                                        SET_YYLLOC();
                                        // printf("this is xqstart\n");
                                        if (yyextra->standard_conforming_strings)
                                                BEGIN(xq);
                                        else
                                                BEGIN(xe);
                                        startlit();
                                }
{xestart}               {
                                        yyextra->warn_on_first_escape = false;
                                        yyextra->saw_non_ascii = false;
                                        SET_YYLLOC();
                                        BEGIN(xe);
                                        startlit();
                                }
{xusstart}              {
                                        SET_YYLLOC();
                                        if (!yyextra->standard_conforming_strings)
                                                yyerror("unsafe use of string constant with Unicode escapes");
                                        BEGIN(xus);
                                        startlit();
                                }

<xb,xh,xq,xe,xus>{quote} {
                                        /*
                                         * When we are scanning a quoted string and see an end
                                         * quote, we must look ahead for a possible continuation.
                                         * If we don't see one, we know the end quote was in fact
                                         * the end of the string.  To reduce the lexer table size,
                                         * we use a single "xqs" state to do the lookahead for all
                                         * types of strings.
                                         */
                                        yyextra->state_before_str_stop = YYSTATE;
                                        BEGIN(xqs);
                                        // printf("state is xqs\n");
                                }
<xqs>{quotecontinue} {
                                        /*
                                         * Found a quote continuation, so return to the in-quote
                                         * state and continue scanning the literal.  Nothing is
                                         * added to the literal's contents.
                                         */
                                        BEGIN(yyextra->state_before_str_stop);
                                        // printf("end state of xqs\n");
                                }
<xqs>{quotecontinuefail} |
<xqs>{other} |
<xqs><<EOF>>    {
                                        /*
                                         * Failed to see a quote continuation.  Throw back
                                         * everything after the end quote, and handle the string
                                         * according to the state we were in previously.
                                         */
        yyless(0);
        BEGIN(INITIAL);

        switch (yyextra->state_before_str_stop)
        {
                case xb:
                        yylval->str = litbufdup(yyscanner);
                        token_count+=1; return BCONST;
                case xh:
                        yylval->str = litbufdup(yyscanner);
                        token_count+=1; return XCONST;
                case xq:
                case xe:
                        /*
                                * Check that the data remains valid, if it might
                                * have been made invalid by unescaping any chars.
                                */
                        /*if (yyextra->saw_non_ascii)
                                pg_verifymbstr(yyextra->literalbuf,
                                                                yyextra->literallen,
                                                                false);*/
                        yylval->str = litbufdup(yyscanner);
                        printf("for sconst test1\n");
                        token_count+=1; return SCONST;
                case xus:
                        yylval->str = litbufdup(yyscanner);
                        token_count+=1; return USCONST;
                default:
                        yyerror("unhandled previous state in xqs");
        }
        }

<xq,xe,xus>{xqdouble} {
                                        addlitchar('\'', yyscanner);
                                }
<xq,xus>{xqinside}  {
                                        addlit(yytext, yyleng, yyscanner);
                                }
<xe>{xeinside}  {
                                        addlit(yytext, yyleng, yyscanner);
                                }
<xe>{xeunicode} {
                                        pg_wchar        c = strtoul(yytext + 2, NULL, 16);

                                        /*
                                         * For consistency with other productions, issue any
                                         * escape warning with cursor pointing to start of string.
                                         * We might want to change that, someday.
                                         */
                                        check_escape_warning(yyscanner);

                                        PUSH_YYLLOC();
                                        SET_YYLLOC();
                                        if (is_utf16_surrogate_first(c))
                                        {
                                                yyextra->utf16_first_part = c;
                                                BEGIN(xeu);
                                        }
                                        else if (is_utf16_surrogate_second(c))
                                                yyerror("invalid Unicode surrogate pair");
                                        else
                                                addunicode(c, yyscanner);

                                        /* Restore yylloc to be start of string token */
                                        POP_YYLLOC();

                                }
<xeu>{xeunicode} {
                                        pg_wchar        c = strtoul(yytext + 2, NULL, 16);
                                        /* Remember start of overall string token ... */
                                        PUSH_YYLLOC();

                                        SET_YYLLOC();
                                        if (!is_utf16_surrogate_second(c))
                                                yyerror("invalid Unicode surrogate pair");
                                        c = surrogate_pair_to_codepoint(yyextra->utf16_first_part, c);

                                        addunicode(c, yyscanner);
                                        /* Restore yylloc to be start of string token */
                                        POP_YYLLOC();

                                        BEGIN(xe);
                                }
<xeu>. |
<xeu>\n |
<xeu><<EOF>>    {
                                        SET_YYLLOC();
                                        yyerror("invalid Unicode surrogate pair");
                                        yyterminate();
                                }
<xe,xeu>{xeunicodefail} {
                                        SET_YYLLOC();
                                        yyerror("invalid Unicode escape");
                                        yyterminate();
                                }
<xe>{xeescape}  {
                                        if (yytext[1] == '\'')
                                        {
                                                if (yyextra->backslash_quote == BACKSLASH_QUOTE_OFF ||
                                                        yyextra->backslash_quote == BACKSLASH_QUOTE_SAFE_ENCODING)
                                                        yyerror("unsafe use of \\' in a string literal");
                                        }
                                        check_string_escape_warning(yytext[1], yyscanner);
                                        addlitchar(unescape_single_char(yytext[1], yyscanner),
                                                           yyscanner);
                                }
<xe>{xeoctesc}  {
                                        unsigned char c = strtoul(yytext + 1, NULL, 8);

                                        check_escape_warning(yyscanner);
                                        addlitchar(c, yyscanner);
                                        if (c == '\0' || IS_HIGHBIT_SET(c))
                                                yyextra->saw_non_ascii = true;
                                }
<xe>{xehexesc}  {
                                        unsigned char c = strtoul(yytext + 2, NULL, 16);

                                        check_escape_warning(yyscanner);
                                        addlitchar(c, yyscanner);
                                        if (c == '\0' || IS_HIGHBIT_SET(c))
                                                yyextra->saw_non_ascii = true;
                                }
<xe>.                   {
                                        /* This is only needed for \ just before EOF */
                                        addlitchar(yytext[0], yyscanner);
                                }
<xq,xe,xus><<EOF>>              { yyerror("unterminated quoted string"); yyterminate();}
{xdstart}               {
                                        SET_YYLLOC();
                                        BEGIN(xd);
                                        startlit();
                                }
{xuistart}              {
                                        SET_YYLLOC();
                                        BEGIN(xui);
                                        startlit();
                                }
<xd>{xdstop}    {
                char       *ident;

                BEGIN(INITIAL);
                if (yyextra->literallen == 0)
                        yyerror("zero-length delimited identifier");
                ident = litbufdup(yyscanner);
                if (yyextra->literallen >= NAMEDATALEN)
                        truncate_identifier(ident, yyextra->literallen, true);
                yylval->str = ident;
                printf("for ident test2\n");
                token_count+=1; return IDENT;
                                }
<xui>{dquote}   {
                                        BEGIN(INITIAL);
                                        if (yyextra->literallen == 0)
                                                yyerror("zero-length delimited identifier");
                                        /* can't truncate till after we de-escape the ident */
                                        yylval->str = litbufdup(yyscanner);
                                        token_count+=1; return UIDENT;
                                }
<xd,xui>{xddouble}      {
                                        addlitchar('"', yyscanner);
                                }
<xd,xui>{xdinside}      {
                                        addlit(yytext, yyleng, yyscanner);
                                }
<xd,xui><<EOF>>         { yyerror("unterminated quoted identifier"); yyterminate();}

{xufailed}      {
                                        char       *ident;

                                        SET_YYLLOC();
                                        /* throw back all but the initial u/U */
                                        yyless(1);
                                        /* and treat it as {identifier} */
                                        ident = downcase_identifier(yytext, yyleng, true,true);
                                        yylval->str = ident;
                                        token_count+=1; return IDENT;
                                }




{integer}               {
                                        SET_YYLLOC();
                                        token_count+=1; return process_integer_literal(yytext, yylval);
                                }
{decimal}               {
                                        SET_YYLLOC();
                                        yylval->str = pstrdup(yytext);
                                        token_count+=1; return FCONST;
                                }
{decimalfail}   {
                                        /* throw back the .., and treat as integer */
                                        yyless(yyleng - 2);
                                        SET_YYLLOC();
                                        token_count+=1; return process_integer_literal(yytext, yylval);
                                }
{identifier}    {
                                        int			nchars = yyleng;
                                        int                     kwnum;
                                        char       *ident;

                                        SET_YYLLOC();
                                        /* Is it a keyword? */
                                        kwnum = ScanKeywordLookup(yytext,
                                                                                          yyextra->keywordlist);
                                        if (kwnum >= 0)
                                        {
                                                yylval->keyword = GetScanKeyword(kwnum,

  yyextra->keywordlist);
                                                token_count+=1; return yyextra->keyword_tokens[kwnum];
                                        }


                                        ident = downcase_identifier(yytext, yyleng, true,true);
                                        yylval->str = ident;

                                        token_count+=1; return IDENT;
                                }
{other}                 {
                                        SET_YYLLOC();
                                        token_count+=1; return yytext[0];
                                }

<<EOF>>                 {
                                        SET_YYLLOC();
                                        yyterminate();
                                }

%%

#undef yyextra
#define yyextra  (((struct yyguts_t *) yyscanner)->yyextra_r)

#undef yylloc
#define yylloc  (((struct yyguts_t *) yyscanner)->yylloc_r)
#undef yyleng
#define yyleng  (((struct yyguts_t *) yyscanner)->yyleng_r)

void
scanner_yyerror(const char *message, core_yyscan_t yyscanner)
{
        // fprintf(stderr,"%s at end of input\n", message);
}

core_yyscan_t
scanner_init(const char *str,
                         core_yy_extra_type *yyext,
                         const ScanKeywordList *keywordlist,
                         const uint16 *keyword_tokens)
{
        Size            slen = strlen(str);
        yyscan_t        scanner;

        if (yylex_init(&scanner) != 0)
                fprintf(stderr,"yylex_init() failed");

        yyset_extra(yyext, scanner);

        yyext->keywordlist = keywordlist;
        yyext->keyword_tokens = keyword_tokens;

        yyext->backslash_quote = backslash_quote;
        yyext->escape_string_warning = escape_string_warning;
        yyext->standard_conforming_strings = standard_conforming_strings;

        /*
         * Make a scan buffer with special termination needed by flex.
         */
        /*yyext->scanbuf = (char *) palloc(slen + 2);
        yyext->scanbuflen = slen;
        memcpy(yyext->scanbuf, str, slen);
        yyext->scanbuf[slen] = yyext->scanbuf[slen + 1] = YY_END_OF_BUFFER_CHAR;
        yy_scan_buffer(yyext->scanbuf, slen + 2, scanner);*/

        /* initialize literal buffer to a reasonable but expansible size */
        /*yyext->literalalloc = 1024;
        yyext->literalbuf = (char *) palloc(yyext->literalalloc);
        yyext->literallen = 0;*/

        return scanner;
}
void
scanner_finish(core_yyscan_t yyscanner)
{
        /*
         * We don't bother to call yylex_destroy(), because all it would do is
         * pfree a small amount of control storage.  It's cheaper to leak the
         * storage until the parsing context is destroyed.  The amount of space
         * involved is usually negligible compared to the output parse tree
         * anyway.
         *
         * We do bother to pfree the scanbuf and literal buffer, but only if they
         * represent a nontrivial amount of space.  The 8K cutoff is arbitrary.
         */
        if (yyextra->scanbuflen >= 8192)
                pfree(yyextra->scanbuf);
        if (yyextra->literalalloc >= 8192)
                pfree(yyextra->literalbuf);
}

static void
addlit(char *ytext, int yleng, core_yyscan_t yyscanner)
{
        /* enlarge buffer if needed */
        if ((yyextra->literallen + yleng) >= yyextra->literalalloc)
        {
                yyextra->literalalloc = pg_nextpower2_32(yyextra->literallen + yleng + 1);
                yyextra->literalbuf = (char *) repalloc(yyextra->literalbuf,
                                                                                                yyextra->literalalloc);
        }
        /* append new data */
        memcpy(yyextra->literalbuf + yyextra->literallen, ytext, yleng);
        yyextra->literallen += yleng;
}

static void
addlitchar(unsigned char ychar, core_yyscan_t yyscanner)
{
        /* enlarge buffer if needed */
        if ((yyextra->literallen + 1) >= yyextra->literalalloc)
        {
                yyextra->literalalloc *= 2;
                yyextra->literalbuf = (char *) repalloc(yyextra->literalbuf,
                                                                                                yyextra->literalalloc);
        }
        /* append new data */
        yyextra->literalbuf[yyextra->literallen] = ychar;
        yyextra->literallen += 1;
}

static char *
litbufdup(core_yyscan_t yyscanner)
{
        int                     llen = yyextra->literallen;
        char       *new;


        new = palloc(llen + 1);
        memcpy(new, yyextra->literalbuf, llen);
        new[llen] = '\0';
        return new;
}

static int
process_integer_literal(const char *token, YYSTYPE *lval)
{
        int                     val;
        char       *endptr;

        errno = 0;
        val = (int) strtol(token, &endptr, 10);
        if (*endptr != '\0' || errno == ERANGE)
        {
                /* integer too large (or contains decimal pt), treat it as a float */
                lval->str = pstrdup(token);
                return FCONST;
        }
        lval->ival = val;
        return ICONST;
}

static void
addunicode(pg_wchar c, core_yyscan_t yyscanner)
{
        char            buf[MAX_UNICODE_EQUIVALENT_STRING + 1];

        if (!is_valid_unicode_codepoint(c))
                yyerror("invalid Unicode escape value");

        /*
         * We expect that pg_unicode_to_server() will complain about any
         * unconvertible code point, so we don't have to set saw_non_ascii.
         */
        pg_unicode_to_server(c, (unsigned char *) buf);
        addlit(buf, strlen(buf), yyscanner);
}

static unsigned char
unescape_single_char(unsigned char c, core_yyscan_t yyscanner)
{
        switch (c)
        {
                case 'b':
                        return '\b';
                case 'f':
                        return '\f';
                case 'n':
                        return '\n';
                case 'r':
                        return '\r';
                case 't':
                        return '\t';
                default:
                        /* check for backslash followed by non-7-bit-ASCII */
                        if (c == '\0' || IS_HIGHBIT_SET(c))
                                yyextra->saw_non_ascii = true;

                        return c;
        }
}

static void
check_string_escape_warning(unsigned char ychar, core_yyscan_t yyscanner)
{
        if (ychar == '\'')
        {
                if (yyextra->warn_on_first_escape && yyextra->escape_string_warning)
                        yyerror("nonstandard use of \\' in a string literal");
                yyextra->warn_on_first_escape = false;  /* warn only once per string */
        }
        else if (ychar == '\\')
        {
                if (yyextra->warn_on_first_escape && yyextra->escape_string_warning)
                        yyerror("nonstandard use of \\' in a string literal");
                yyextra->warn_on_first_escape = false;  /* warn only once per string */
        }
        else
                check_escape_warning(yyscanner);
}

static void
check_escape_warning(core_yyscan_t yyscanner)
{
        if (yyextra->warn_on_first_escape && yyextra->escape_string_warning)
                        yyerror("nonstandard use of escape in a string literal");
        yyextra->warn_on_first_escape = false;          /* warn only once per string */
}

void *
core_yyalloc(yy_size_t bytes, core_yyscan_t yyscanner)
{
        return palloc(bytes);
}

void *
core_yyrealloc(void *ptr, yy_size_t bytes, core_yyscan_t yyscanner)
{
        if (ptr)
                return repalloc(ptr, bytes);
        else
                return palloc(bytes);
}

void
core_yyfree(void *ptr, core_yyscan_t yyscanner)
{
        if (ptr)
                pfree(ptr);
}