#include <assert.h>
#include "../include/ognl-parser.h"
#include "../include/ognl.tab.h"
#include "../include/gramparse.h"
#include "../include/kwlist_d.h"

// #include "../include/sql.lex.h"

// typedef struct yy_buffer_state *YY_BUFFER_STATE;
typedef size_t yy_size_t;
struct yy_buffer_state
	{
/* %if-c-only */
	FILE *yy_input_file;
/* %endif */

/* %if-c++-only */
/* %endif */

	char *yy_ch_buf;		/* input buffer */
	char *yy_buf_pos;		/* current position in input buffer */

	/* Size of input buffer in bytes, not including room for EOB
	 * characters.
	 */
	int yy_buf_size;

	/* Number of characters read into yy_ch_buf, not including EOB
	 * characters.
	 */
	yy_size_t yy_n_chars;

	/* Whether we "own" the buffer - i.e., we know we created it,
	 * and can realloc() it to grow it, and should free() it to
	 * delete it.
	 */
	int yy_is_our_buffer;

	/* Whether this is an "interactive" input source; if so, and
	 * if we're using stdio for input, then we want to use getc()
	 * instead of fread(), to make sure we stop fetching input after
	 * each newline.
	 */
	int yy_is_interactive;

	/* Whether we're considered to be at the beginning of a line.
	 * If so, '^' rules will be active on the next match, otherwise
	 * not.
	 */
	int yy_at_bol;

    int yy_bs_lineno; /**< The line count. */
    int yy_bs_column; /**< The column count. */

	/* Whether to try to fill the input buffer when we reach the
	 * end of it.
	 */
	int yy_fill_buffer;

	int yy_buffer_status;

// #define YY_BUFFER_NEW 0
// #define YY_BUFFER_NORMAL 1
	/* When an EOF's been seen but there's still some text to process
	 * then we mark the buffer as YY_EOF_PENDING, to indicate that we
	 * shouldn't try reading from the input source any more.  We might
	 * still have a bunch of tokens to match, though, because of
	 * possible backing-up.
	 *
	 * When we actually see the EOF, we change the status to "new"
	 * (via yyrestart()), so that the user can continue scanning by
	 * just pointing yyin at a new input file.
	 */
// #define YY_BUFFER_EOF_PENDING 2

	};
typedef struct yy_buffer_state *YY_BUFFER_STATE;
/*
 * ScanKeywordLookup - see if a given word is a keyword
 *
 * The list of keywords to be matched against is passed as a ScanKeywordList.
 *
 * Returns the keyword number (0..N-1) of the keyword, or -1 if no match.
 * Callers typically use the keyword number to index into information
 * arrays, but that is no concern of this code.
 *
 * The match is done case-insensitively.  Note that we deliberately use a
 * dumbed-down case conversion that will only translate 'A'-'Z' into 'a'-'z',
 * even if we are in a locale where tolower() would produce more or different
 * translations.  This is to conform to the SQL99 spec, which says that
 * keywords are to be matched in this way even though non-keyword identifiers
 * receive a different case-normalization mapping.
 */
int ScanKeywordLookup(const char *str,
              const ScanKeywordList *keywords)
{
    size_t len;
    int h;
    const char *kw;

    /*
     * Reject immediately if too long to be any keyword.  This saves useless
     * hashing and downcasing work on long strings.
     */
    len = strlen(str);
    if (len > keywords->max_kw_len)
        return -1;

    /*
     * Compute the hash function.  We assume it was generated to produce
     * case-insensitive results.  Since it's a perfect hash, we need only
     * match to the specific keyword it identifies.
     */
    h = keywords->hash(str, len);

    /* An out-of-range result implies no match */
    if (h < 0 || h >= keywords->num_keywords)
        return -1;

    /*
     * Compare character-by-character to see if we have a match, applying an
     * ASCII-only downcasing to the input characters.  We must not use
     * tolower() since it may produce the wrong translation in some locales
     * (eg, Turkish).
     */
    kw = GetScanKeyword(h, keywords);
    while (*str != '\0')
    {
        char ch = *str++;

        if (ch >= 'A' && ch <= 'Z')
            ch += 'a' - 'A';
        if (ch != *kw++)
            return -1;
    }
    if (*kw != '\0')
        return -1;

    /* Success! */
    return h;
}

static inline void *
pg_malloc_internal(size_t size, int flags)
{
    void *tmp;

    /* Avoid unportable behavior of malloc(0) */
    if (size == 0)
        size = 1;
    tmp = malloc(size);
    if (tmp == NULL)
    {
        if ((flags & MCXT_ALLOC_NO_OOM) == 0)
        {
            fprintf(stderr, "out of memory\n");
            exit(EXIT_FAILURE);
        }
        return NULL;
    }

    if ((flags & MCXT_ALLOC_ZERO) != 0)
        MemSet(tmp, 0, size);
    return tmp;
}
void *
pg_malloc(size_t size)
{
    return pg_malloc_internal(size, 0);
}

void *
pg_malloc0(size_t size)
{
    return pg_malloc_internal(size, MCXT_ALLOC_ZERO);
}

void *
pg_malloc_extended(size_t size, int flags)
{
    return pg_malloc_internal(size, flags);
}

void *
pg_realloc(void *ptr, size_t size)
{
    void *tmp;

    /* Avoid unportable behavior of realloc(NULL, 0) */
    if (ptr == NULL && size == 0)
        size = 1;
    tmp = realloc(ptr, size);
    if (!tmp)
    {
        fprintf(stderr, "out of memory\n");
        exit(EXIT_FAILURE);
    }
    return tmp;
}

/*
 * "Safe" wrapper around strdup().
 */
char *
pg_strdup(const char *in)
{
    char *tmp;

    if (!in)
    {
        fprintf(stderr,
            "cannot duplicate null pointer (internal error)\n");
        exit(EXIT_FAILURE);
    }
    tmp = strdup(in);
    if (!tmp)
    {
        fprintf(stderr, "out of memory\n");
        exit(EXIT_FAILURE);
    }
    return tmp;
}

void pg_free(void *ptr)
{
    if (ptr != NULL)
        free(ptr);
}

/*
 * Frontend emulation of backend memory management functions.  Useful for
 * programs that compile backend files.
 */
void *
palloc(Size size)
{
    return pg_malloc_internal(size, 0);
}

void *
palloc0(Size size)
{
    return pg_malloc_internal(size, MCXT_ALLOC_ZERO);
}

void *
palloc_extended(Size size, int flags)
{
    return pg_malloc_internal(size, flags);
}

void pfree(void *pointer)
{
    pg_free(pointer);
}

char *
pstrdup(const char *in)
{
    return pg_strdup(in);
}
char *
pnstrdup(const char *in, Size size)
{
    char *tmp;
    int len;

    if (!in)
    {
        fprintf(stderr,
            "cannot duplicate null pointer (internal error)\n");
        exit(EXIT_FAILURE);
    }

    len = strnlen(in, size);
    tmp = (char *)malloc(len + 1);
    if (tmp == NULL)
    {
        fprintf(stderr, "out of memory\n");
        exit(EXIT_FAILURE);
    }

    memcpy(tmp, in, len);
    tmp[len] = '\0';

    return tmp;
}
void *
repalloc(void *pointer, Size size)
{
    return pg_realloc(pointer, size);
}

/*
 * truncate_identifier() --- truncate an identifier to NAMEDATALEN-1 bytes.
 *
 * The given string is modified in-place, if necessary.  A warning is
 * issued if requested.
 *
 * We require the caller to pass in the string length since this saves a
 * strlen() call in some common usages.
 */
void truncate_identifier(char *ident, int len, bool warn)
{
    if (len >= NAMEDATALEN)
    {
        len = cliplen(ident, len, NAMEDATALEN - 1);
        ident[len] = '\0';
    }
}

/*
 * a workhorse for downcase_truncate_identifier
 */
char *
downcase_identifier(const char *ident, int len, bool warn, bool truncate)
{
    char *result;
    int i;
    bool enc_is_single_byte;

    result = (char *)palloc(len + 1);
    enc_is_single_byte = true;

    /*
     * SQL99 specifies Unicode-aware case normalization, which we don't yet
     * have the infrastructure for.  Instead we use tolower() to provide a
     * locale-aware translation.  However, there are some locales where this
     * is not right either (eg, Turkish may do strange things with 'i' and
     * 'I').  Our current compromise is to use tolower() for characters with
     * the high bit set, as long as they aren't part of a multi-byte
     * character, and use an ASCII-only downcasing for 7-bit characters.
     */
    for (i = 0; i < len; i++)
    {
        unsigned char ch = (unsigned char)ident[i];

        if (ch >= 'A' && ch <= 'Z')
            ch += 'a' - 'A';
        else if (enc_is_single_byte && IS_HIGHBIT_SET(ch) && isupper(ch))
            ch = tolower(ch);
        result[i] = (char)ch;
    }
    result[i] = '\0';

    if (i >= NAMEDATALEN && truncate)
        truncate_identifier(result, i, warn);

    return result;
}

/*
 * Convert a single Unicode code point into a string in the server encoding.
 *
 * The code point given by "c" is converted and stored at *s, which must
 * have at least MAX_UNICODE_EQUIVALENT_STRING+1 bytes available.
 * The output will have a trailing '\0'.  Throws error if the conversion
 * cannot be performed.
 *
 * Note that this relies on having previously looked up any required
 * conversion function.  That's partly for speed but mostly because the parser
 * may call this outside any transaction, or in an aborted transaction.
 */
void pg_unicode_to_server(pg_wchar c, unsigned char *s)
{
    /*unsigned char c_as_utf8[MAX_MULTIBYTE_CHAR_LEN + 1];
    int     c_as_utf8_len;
    int     server_encoding;*/

    /*
     * Complain if invalid Unicode code point.  The choice of errcode here is
     * debatable, but really our caller should have checked this anyway.
     */
    if (!is_valid_unicode_codepoint(c))
        return;

    /* Otherwise, if it's in ASCII range, conversion is trivial */
    if (c <= 0x7F)
    {
        s[0] = (unsigned char)c;
        s[1] = '\0';
        return;
    }
}

/*
 * scanner_isspace() --- return true if flex scanner considers char whitespace
 *
 * This should be used instead of the potentially locale-dependent isspace()
 * function when it's important to match the lexer's behavior.
 *
 * In principle we might need similar functions for isalnum etc, but for the
 * moment only isspace seems needed.
 */
bool scanner_isspace(char ch)
{
    /* This must match scan.l's list of {space} characters */
    if (ch == ' ' ||
        ch == '\t' ||
        ch == '\n' ||
        ch == '\r' ||
        ch == '\f')
        return true;
    return false;
}

/* convert hex digit (caller should have verified that) to value */
static unsigned int
hexval(unsigned char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';
    if (c >= 'a' && c <= 'f')
        return c - 'a' + 0xA;
    if (c >= 'A' && c <= 'F')
        return c - 'A' + 0xA;
    fprintf(stderr, "invalid hexadecimal digit");
    return 0; /* not reached */
}

/* is Unicode code point acceptable? */
static void
check_unicode_value(pg_wchar c)
{
    if (!is_valid_unicode_codepoint(c))
        fprintf(stderr, "invalid Unicode escape value");
}

/* is 'escape' acceptable as Unicode escape character (UESCAPE syntax) ? */
static bool
check_uescapechar(unsigned char escape)
{
    if (isxdigit(escape) || escape == '+' || escape == '\'' || escape == '"' || scanner_isspace(escape))
        return false;
    else
        return true;
}
/*
 * Process Unicode escapes in "str", producing a palloc'd plain string
 *
 * escape: the escape character to use
 * position: start position of U&'' or U&"" string token
 * yyscanner: context information needed for error reports
 */
static char *
str_udeescape(const char *str, char escape,
          int position, core_yyscan_t yyscanner)
{
    const char *in;
    char *new,
        *out;
    size_t new_len;
    pg_wchar pair_first = 0;

    /*
     * Guesstimate that result will be no longer than input, but allow enough
     * padding for Unicode conversion.
     */
    new_len = strlen(str) + MAX_UNICODE_EQUIVALENT_STRING + 1;
    new = palloc(new_len);

    in = str;
    out = new;
    while (*in)
    {
        /* Enlarge string if needed */
        size_t out_dist = out - new;

        if (out_dist > new_len - (MAX_UNICODE_EQUIVALENT_STRING + 1))
        {
            new_len *= 2;
            new = repalloc(new, new_len);
            out = new + out_dist;
        }

        if (in[0] == escape)
        {
            /*
             * Any errors reported while processing this escape sequence will
             * have an error cursor pointing at the escape.
             */
            if (in[1] == escape)
            {
                if (pair_first)
                    goto invalid_pair;
                *out++ = escape;
                in += 2;
            }
            else if (isxdigit((unsigned char)in[1]) &&
                 isxdigit((unsigned char)in[2]) &&
                 isxdigit((unsigned char)in[3]) &&
                 isxdigit((unsigned char)in[4]))
            {
                pg_wchar unicode;

                unicode = (hexval(in[1]) << 12) +
                      (hexval(in[2]) << 8) +
                      (hexval(in[3]) << 4) +
                      hexval(in[4]);
                check_unicode_value(unicode);
                if (pair_first)
                {
                    if (is_utf16_surrogate_second(unicode))
                    {
                        unicode = surrogate_pair_to_codepoint(pair_first, unicode);
                        pair_first = 0;
                    }
                    else
                        goto invalid_pair;
                }
                else if (is_utf16_surrogate_second(unicode))
                    goto invalid_pair;

                if (is_utf16_surrogate_first(unicode))
                    pair_first = unicode;
                else
                {
                    pg_unicode_to_server(unicode, (unsigned char *)out);
                    out += strlen(out);
                }
                in += 5;
            }
            else if (in[1] == '+' &&
                 isxdigit((unsigned char)in[2]) &&
                 isxdigit((unsigned char)in[3]) &&
                 isxdigit((unsigned char)in[4]) &&
                 isxdigit((unsigned char)in[5]) &&
                 isxdigit((unsigned char)in[6]) &&
                 isxdigit((unsigned char)in[7]))
            {
                pg_wchar unicode;

                unicode = (hexval(in[2]) << 20) +
                      (hexval(in[3]) << 16) +
                      (hexval(in[4]) << 12) +
                      (hexval(in[5]) << 8) +
                      (hexval(in[6]) << 4) +
                      hexval(in[7]);
                check_unicode_value(unicode);
                if (pair_first)
                {
                    if (is_utf16_surrogate_second(unicode))
                    {
                        unicode = surrogate_pair_to_codepoint(pair_first, unicode);
                        pair_first = 0;
                    }
                    else
                        goto invalid_pair;
                }
                else if (is_utf16_surrogate_second(unicode))
                    goto invalid_pair;

                if (is_utf16_surrogate_first(unicode))
                    pair_first = unicode;
                else
                {
                    pg_unicode_to_server(unicode, (unsigned char *)out);
                    out += strlen(out);
                }
                in += 8;
            }
            else
                fprintf(stderr, "invalid Unicode escape");
        }
        else
        {
            if (pair_first)
                goto invalid_pair;

            *out++ = *in++;
        }
    }
    /* unfinished surrogate pair? */
    if (pair_first)
        goto invalid_pair;

    *out = '\0';
    return new;

    /*
     * We might get here with the error callback active, or not.  Call
     * scanner_errposition to make sure an error cursor appears; if the
     * callback is active, this is duplicative but harmless.
     */
invalid_pair:
    fprintf(stderr, "invalid Unicode surrogate pair");
    return NULL; /* keep compiler quiet */
}

/*
 * Intermediate filter between parser and core lexer (core_yylex in scan.l).
 *
 * This filter is needed because in some cases the standard SQL grammar
 * requires more than one token lookahead.  We reduce these cases to one-token
 * lookahead by replacing tokens here, in order to keep the grammar LALR(1).
 *
 * Using a filter is simpler than trying to recognize multiword tokens
 * directly in scan.l, because we'd have to allow for comments between the
 * words.  Furthermore it's not clear how to do that without re-introducing
 * scanner backtrack, which would cost more performance than this filter
 * layer does.
 *
 * We also use this filter to convert UIDENT and USCONST sequences into
 * plain IDENT and SCONST tokens.  While that could be handled by additional
 * productions in the main grammar, it's more efficient to do it like this.
 *
 * The filter also provides a convenient place to translate between
 * the core_YYSTYPE and YYSTYPE representations (which are really the
 * same thing anyway, but notationally they're different).
 */

int base_yylex(YYSTYPE *lvalp, YYLTYPE *llocp, int *token_list, int *token_index)
{
    int cur_token = token_list[*token_index];
    *token_index += 1;

    return cur_token;
}

int base_yylex1(YYSTYPE *lvalp, YYLTYPE *llocp, core_yyscan_t yyscanner)
{
    base_yy_extra_type *yyextra = pg_yyget_extra(yyscanner);
    int cur_token;
    int next_token;
    int cur_token_length;
    YYLTYPE cur_yylloc;

    /* Get next token --- we might already have it */
    if (yyextra->have_lookahead)
    {
        cur_token = yyextra->lookahead_token;
        lvalp->core_yystype = yyextra->lookahead_yylval;
        *llocp = yyextra->lookahead_yylloc;
        if (yyextra->lookahead_end)
            *(yyextra->lookahead_end) = yyextra->lookahead_hold_char;
        yyextra->have_lookahead = false;
    }
    else
        cur_token = core_yylex(&(lvalp->core_yystype), llocp, yyscanner);
    /*
     * If this token isn't one that requires lookahead, just return it.  If it
     * does, determine the token length.  (We could get that via strlen(), but
     * since we have such a small set of possibilities, hardwiring seems
     * feasible and more efficient --- at least for the fixed-length cases.)
     */
    switch (cur_token)
    {
    case UIDENT:
        cur_token_length = strlen(yyextra->core_yy_extra.scanbuf + *llocp);
        break;
    default:
        return cur_token;
    }
    // printf("cur_token is %d\n",cur_token);

    /*
     * Identify end+1 of current token.  core_yylex() has temporarily stored a
     * '\0' here, and will undo that when we call it again.  We need to redo
     * it to fully revert the lookahead call for error reporting purposes.
     */
    yyextra->lookahead_end = yyextra->core_yy_extra.scanbuf +
                 *llocp + cur_token_length;

    // printf("lookahead_end is %c\n",*(yyextra->lookahead_end));
    // printf("shift is %d\n", *llocp);
    // printf("cur token length is %d\n",cur_token_length);

    assert(*(yyextra->lookahead_end) == '\0');

    /*
     * Save and restore *llocp around the call.  It might look like we could
     * avoid this by just passing &lookahead_yylloc to core_yylex(), but that
     * does not work because flex actually holds onto the last-passed pointer
     * internally, and will use that for error reporting.  We need any error
     * reports to point to the current token, not the next one.
     */
    cur_yylloc = *llocp;

    /* Get next token, saving outputs into lookahead variables */
    next_token = core_yylex(&(yyextra->lookahead_yylval), llocp, yyscanner);
    yyextra->lookahead_token = next_token;
    yyextra->lookahead_yylloc = *llocp;

    *llocp = cur_yylloc;

    /* Now revert the un-truncation of the current token */
    yyextra->lookahead_hold_char = *(yyextra->lookahead_end);
    *(yyextra->lookahead_end) = '\0';

    yyextra->have_lookahead = true;

    return cur_token;
}

int init_token_list(char *str, int *token_list, int max_len)
{
    int i;

    core_yyscan_t yyscanner;
    base_yy_extra_type yyextra_t;

    int backslash_quote = BACKSLASH_QUOTE_SAFE_ENCODING;
    bool escape_string_warning = true;
    bool standard_conforming_strings = true;

    struct core_yy_extra_type *yyext = &yyextra_t.core_yy_extra;
    if (core_yylex_init(&yyscanner) != 0)
        fprintf(stderr, "yylex_init() failed");

    core_yyset_extra(yyext, yyscanner);

    yyext->keywordlist = &ScanKeywords;
    yyext->keyword_tokens = ScanKeywordTokens;

    yyext->backslash_quote = backslash_quote;
    yyext->escape_string_warning = escape_string_warning;
    yyext->standard_conforming_strings = standard_conforming_strings;

    /*
     * Make a scan buffer with special termination needed by flex.
     */

    Size slen = strlen(str);
    yyext->scanbuf = (char *)palloc(slen + 2);
    yyext->scanbuflen = slen;
    memcpy(yyext->scanbuf, str, slen);
    yyext->scanbuf[slen] = yyext->scanbuf[slen + 1] = 0;
    core_yy_scan_buffer(yyext->scanbuf, slen + 2, yyscanner);

    /* initialize literal buffer to a reasonable but expansible size */
    yyext->literalalloc = 1024;
    yyext->literalbuf = (char *)palloc(yyext->literalalloc);
    yyext->literallen = 0;

    yyextra_t.have_lookahead = false;

    YYSTYPE lyval;
    YYLTYPE yylloc = 0;
    int token = 10000;

    for (i = 0; i < max_len; i++)
        token_list[i] = -2;

    int input_len = 0;
    while (token > YYEOF)
    {
        token = base_yylex1(&lyval, &yylloc, yyscanner);
        token_list[input_len] = token;
        input_len += 1;
        if (input_len >= max_len)
            token = YYEOF; // for sqli: Truncate the size of the input string to max_len
        /* Clean up (release memory) */
        scanner_finish(yyscanner); //
    }
    // pfree(b);
    pfree(yyext->scanbuf);
    pfree(yyext->literalbuf);
    core_yyfree(yyscanner);
    return input_len;
}
