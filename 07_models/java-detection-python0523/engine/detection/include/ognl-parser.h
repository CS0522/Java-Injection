#ifndef __SQL_PARSER_H__
#define __SQL_PARSER_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>

#define NAMEDATALEN 64
#define MAX_UNICODE_EQUIVALENT_STRING 16
#define MCXT_ALLOC_ZERO 0x04   /* zero allocated memory */
#define MCXT_ALLOC_NO_OOM 0x02 /* no failure if out-of-memory */

#define EXIT_FAILURE 1
#define LONG_ALIGN_MASK (sizeof(long) - 1)
#define MEMSET_LOOP_LIMIT 1000000

#define Min(x, y) ((x) < (y) ? (x) : (y))

/*
 * MemSet
 *  Exactly the same as standard library function memset(), but considerably
 *  faster for zeroing small word-aligned structures (such as parsetree nodes).
 *  This has to be a macro because the main point is to avoid function-call
 *  overhead.   However, we have also found that the loop is faster than
 *  native libc memset() on some platforms, even those with assembler
 *  memset() functions.  More research needs to be done, perhaps with
 *  MEMSET_LOOP_LIMIT tests in configure.
 */
#define MemSet(start, val, len)                                                               \
    do                                                                                        \
    {                                                                                         \
        /* must be void* because we don't know if it is integer aligned yet */                \
        void *_vstart = (void *)(start);                                                      \
        int _val = (val);                                                                     \
        Size _len = (len);                                                                    \
                                                                                              \
        if ((((uintptr_t)_vstart) & LONG_ALIGN_MASK) == 0 &&                                  \
            (_len & LONG_ALIGN_MASK) == 0 &&                                                  \
            _val == 0 &&                                                                      \
            _len <= MEMSET_LOOP_LIMIT && /*                                                   \
                                          *  If MEMSET_LOOP_LIMIT == 0, optimizer should find \
                                          *  the whole "if" false at compile time.            \
                                          */                                                  \
            MEMSET_LOOP_LIMIT != 0)                                                           \
        {                                                                                     \
            long *_start = (long *)_vstart;                                                   \
            long *_stop = (long *)((char *)_start + _len);                                    \
            while (_start < _stop)                                                            \
                *_start++ = 0;                                                                \
        }                                                                                     \
        else                                                                                  \
            memset(_vstart, _val, _len);                                                      \
    } while (0)

/* msb for char */
#define HIGHBIT (0x80)
#define IS_HIGHBIT_SET(ch) ((unsigned char)(ch)&HIGHBIT)
#define PG_UINT32_MAX (0xFFFFFFFFU)

typedef signed char int8;
typedef signed short int16;
typedef signed int int32;

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

typedef enum
{
    false = (1 == 0),
    true = (!false)
} bool;

typedef unsigned int pg_wchar;
typedef void *core_yyscan_t;
typedef unsigned int pg_char;
typedef size_t Size;

/* Values for the backslash_quote GUC */
typedef enum
{
    BACKSLASH_QUOTE_OFF,
    BACKSLASH_QUOTE_ON,
    BACKSLASH_QUOTE_SAFE_ENCODING
} BackslashQuoteType;

/* Hash function used by ScanKeywordLookup */
typedef int (*ScanKeywordHashFunc)(const void *key, size_t keylen);

typedef struct ScanKeywordList
{
    const char *kw_string;    /* all keywords in order, separated by \0 */
    const uint16 *kw_offsets; /* offsets to the start of each keyword */
    ScanKeywordHashFunc hash; /* perfect hash function for keywords */
    int num_keywords;         /* number of keywords */
    int max_kw_len;           /* length of longest keyword */
} ScanKeywordList;

/*
 * We track token locations in terms of byte offsets from the start of the
 * source string, not the column number/line number representation that
 * bison uses by default.  Also, to minimize overhead we track only one
 * location (usually the first token location) for each construct, not
 * the beginning and ending locations as bison does by default.  It's
 * therefore sufficient to make YYLTYPE an int.
 */
#define YYLTYPE int

typedef struct core_yy_extra_type
{
    /*
     * The string the scanner is physically scanning.  We keep this mainly so
     * that we can cheaply compute the offset of the current token (yytext).
     */
    char *scanbuf;
    Size scanbuflen;

    /*
     * The keyword list to use, and the associated grammar token codes.
     */
    const ScanKeywordList *keywordlist;
    const uint16 *keyword_tokens;

    /*
     * Scanner settings to use.  These are initialized from the corresponding
     * GUC variables by scanner_init().  Callers can modify them after
     * scanner_init() if they don't want the scanner's behavior to follow the
     * prevailing GUC settings.
     */
    int backslash_quote;
    bool escape_string_warning;
    bool standard_conforming_strings;

    /*
     * literalbuf is used to accumulate literal values when multiple rules are
     * needed to parse a single literal.  Call startlit() to reset buffer to
     * empty, addlit() to add text.  NOTE: the string in literalbuf is NOT
     * necessarily null-terminated, but there always IS room to add a trailing
     * null at offset literallen.  We store a null only when we need it.
     */
    char *literalbuf; /* palloc'd expandable buffer */
    int literallen;   /* actual current string length */
    int literalalloc; /* current allocated buffer size */

    /*
     * Random assorted scanner state.
     */
    int state_before_str_stop; /* start cond. before end quote */
    int xcdepth;               /* depth of nesting in slash-star comments */
    char *dolqstart;           /* current $foo$ quote start string */
    YYLTYPE save_yylloc;       /* one-element stack for PUSH_YYLLOC() */

    /* first part of UTF16 surrogate pair for Unicode escapes */
    int32 utf16_first_part;

    /* state variables for literal-lexing warnings */
    bool warn_on_first_escape;
    bool saw_non_ascii;
} core_yy_extra_type;

/*
 * The scanner returns extra data about scanned tokens in this union type.
 * Note that this is a subset of the fields used in YYSTYPE of the bison
 * parsers built atop the scanner.
 */
typedef union core_YYSTYPE
{
    int ival;            /* for integer literals */
    char *str;           /* for identifiers and non-integer literals */
    const char *keyword; /* canonical spelling of keywords */
} core_YYSTYPE;

/* #define FREE             0xfd    free (unused) */
/* #define FREE             0xfe    free (unused) */
/* #define FREE             0xff    free (unused) */

/*----------------------------------------------------
 * end of MULE stuff
 *----------------------------------------------------
 */

/*
 * PostgreSQL encoding identifiers
 *
 * WARNING: the order of this enum must be same as order of entries
 *          in the pg_enc2name_tbl[] array (in src/common/encnames.c), and
 *          in the pg_wchar_table[] array (in src/common/wchar.c)!
 *
 *          If you add some encoding don't forget to check
 *          PG_ENCODING_BE_LAST macro.
 *
 * PG_SQL_ASCII is default encoding and must be = 0.
 *
 * XXX  We must avoid renumbering any backend encoding until libpq's major
 * version number is increased beyond 5; it turns out that the backend
 * encoding IDs are effectively part of libpq's ABI as far as 8.2 initdb and
 * psql are concerned.
 */
typedef enum pg_enc
{
    PG_SQL_ASCII = 0, /* SQL/ASCII */
    PG_EUC_JP,        /* EUC for Japanese */
    PG_EUC_CN,        /* EUC for Chinese */
    PG_EUC_KR,        /* EUC for Korean */
    PG_EUC_TW,        /* EUC for Taiwan */
    PG_EUC_JIS_2004,  /* EUC-JIS-2004 */
    PG_UTF8,          /* Unicode UTF8 */
    PG_MULE_INTERNAL, /* Mule internal code */
    PG_LATIN1,        /* ISO-8859-1 Latin 1 */
    PG_LATIN2,        /* ISO-8859-2 Latin 2 */
    PG_LATIN3,        /* ISO-8859-3 Latin 3 */
    PG_LATIN4,        /* ISO-8859-4 Latin 4 */
    PG_LATIN5,        /* ISO-8859-9 Latin 5 */
    PG_LATIN6,        /* ISO-8859-10 Latin6 */
    PG_LATIN7,        /* ISO-8859-13 Latin7 */
    PG_LATIN8,        /* ISO-8859-14 Latin8 */
    PG_LATIN9,        /* ISO-8859-15 Latin9 */
    PG_LATIN10,       /* ISO-8859-16 Latin10 */
    PG_WIN1256,       /* windows-1256 */
    PG_WIN1258,       /* Windows-1258 */
    PG_WIN866,        /* (MS-DOS CP866) */
    PG_WIN874,        /* windows-874 */
    PG_KOI8R,         /* KOI8-R */
    PG_WIN1251,       /* windows-1251 */
    PG_WIN1252,       /* windows-1252 */
    PG_ISO_8859_5,    /* ISO-8859-5 */
    PG_ISO_8859_6,    /* ISO-8859-6 */
    PG_ISO_8859_7,    /* ISO-8859-7 */
    PG_ISO_8859_8,    /* ISO-8859-8 */
    PG_WIN1250,       /* windows-1250 */
    PG_WIN1253,       /* windows-1253 */
    PG_WIN1254,       /* windows-1254 */
    PG_WIN1255,       /* windows-1255 */
    PG_WIN1257,       /* windows-1257 */
    PG_KOI8U,         /* KOI8-U */
    /* PG_ENCODING_BE_LAST points to the above entry */

    /* followings are for client encoding only */
    PG_SJIS,           /* Shift JIS (Windows-932) */
    PG_BIG5,           /* Big5 (Windows-950) */
    PG_GBK,            /* GBK (Windows-936) */
    PG_UHC,            /* UHC (Windows-949) */
    PG_GB18030,        /* GB18030 */
    PG_JOHAB,          /* EUC for Korean JOHAB */
    PG_SHIFT_JIS_2004, /* Shift-JIS-2004 */
    _PG_LAST_ENCODING_ /* mark only */

} pg_enc;

#define PG_ENCODING_BE_LAST PG_KOI8U
/*
 * Please use these tests before access to pg_enc2name_tbl[]
 * or to other places...
 */
#define PG_VALID_BE_ENCODING(_enc) \
    ((_enc) >= 0 && (_enc) <= PG_ENCODING_BE_LAST)

#define PG_ENCODING_IS_CLIENT_ONLY(_enc) \
    ((_enc) > PG_ENCODING_BE_LAST && (_enc) < _PG_LAST_ENCODING_)

#define PG_VALID_ENCODING(_enc) \
    ((_enc) >= 0 && (_enc) < _PG_LAST_ENCODING_)

/* On FE are possible all encodings */
#define PG_VALID_FE_ENCODING(_enc) PG_VALID_ENCODING(_enc)

/*
 * Some handy functions for Unicode-specific tests.
 */
static inline bool
is_valid_unicode_codepoint(pg_wchar c)
{
    return (c > 0 && c <= 0x10FFFF);
}

static inline bool
is_utf16_surrogate_first(pg_wchar c)
{
    return (c >= 0xD800 && c <= 0xDBFF);
}

static inline bool
is_utf16_surrogate_second(pg_wchar c)
{
    return (c >= 0xDC00 && c <= 0xDFFF);
}

static inline pg_wchar
surrogate_pair_to_codepoint(pg_wchar first, pg_wchar second)
{
    return ((first & 0x3FF) << 10) + 0x10000 + (second & 0x3FF);
}

/* mbcliplen for any single-byte encoding */
static int
cliplen(const char *str, int len, int limit)
{
    int l = 0;

    len = Min(len, limit);
    while (l < len && str[l])
        l++;
    return l;
}

/* Code that wants to retrieve the text of the N'th keyword should use this. */
static inline const char *
GetScanKeyword(int n, const ScanKeywordList *keywords)
{
    return keywords->kw_string + keywords->kw_offsets[n];
}

/* Constant data exported from parser/scan.l */
extern const uint16 ScanKeywordTokens[];

extern int ScanKeywordLookup(const char *str, const ScanKeywordList *keywords);

extern void *pg_malloc(size_t size);
extern void *pg_malloc0(size_t size);
extern void *pg_malloc_extended(size_t size, int flags);
extern void *pg_realloc(void *ptr, size_t size);
extern char *pg_strdup(const char *in);
extern void pg_free(void *ptr);

extern void *palloc(Size size);
extern void *palloc0(Size size);
extern void *palloc_extended(Size size, int flags);
extern void pfree(void *pointer);
extern char *pstrdup(const char *in);
extern char *pnstrdup(const char *in, Size size);
extern void *repalloc(void *pointer, Size size);

extern void truncate_identifier(char *ident, int len, bool warn);
extern char *downcase_identifier(const char *ident, int len, bool warn, bool truncate);
extern void pg_unicode_to_server(pg_wchar c, unsigned char *s);

extern int init_token_list(char *str, int *token_list, int max_len);

#endif /* __SQL_PARSER_H__ */
