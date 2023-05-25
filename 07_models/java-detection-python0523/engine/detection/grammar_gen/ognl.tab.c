/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         base_yyparse
#define yylex           base_yylex
#define yyerror         base_yyerror
#define yydebug         base_yydebug
#define yynerrs         base_yynerrs

/* First part of user prologue.  */
#line 1 "../grammar/ognl.y"

#define YYDEBUG 1
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "../include/ognl-parser.h"
#include "../include/../include/ognl.tab.h"

#define YYLLOC_DEFAULT(Current, Rhs, N) \
        do { \
                if ((N) > 0) \
                        (Current) = (Rhs)[1]; \
                else \
                        (Current) = (-1); \
        } while (0)
#define YYMALLOC palloc
#define YYFREE   pfree

#line 95 "ognl.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "../include/ognl.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_AND = 3,                        /* AND  */
  YYSYMBOL_BEANS = 4,                      /* BEANS  */
  YYSYMBOL_BUFFEREDINPUTSTREAM = 5,        /* BUFFEREDINPUTSTREAM  */
  YYSYMBOL_BUFFEREDREADER = 6,             /* BUFFEREDREADER  */
  YYSYMBOL_BYTEARRAYINPUTSTREAM = 7,       /* BYTEARRAYINPUTSTREAM  */
  YYSYMBOL_BYTEARRAYOUTPUTSTREAM = 8,      /* BYTEARRAYOUTPUTSTREAM  */
  YYSYMBOL_CHARARRAYREADER = 9,            /* CHARARRAYREADER  */
  YYSYMBOL_CLASS = 10,                     /* CLASS  */
  YYSYMBOL_CLASSLOADER = 11,               /* CLASSLOADER  */
  YYSYMBOL_COLLECTIONS = 12,               /* COLLECTIONS  */
  YYSYMBOL_COMMAND = 13,                   /* COMMAND  */
  YYSYMBOL_COMPILER = 14,                  /* COMPILER  */
  YYSYMBOL_CONTENT = 15,                   /* CONTENT  */
  YYSYMBOL_CONTEXT = 16,                   /* CONTEXT  */
  YYSYMBOL_DATAINPUTSTREAM = 17,           /* DATAINPUTSTREAM  */
  YYSYMBOL_DEBUG = 18,                     /* DEBUG  */
  YYSYMBOL_DEFAULT_MEMBER_ACCESS = 19,     /* DEFAULT_MEMBER_ACCESS  */
  YYSYMBOL_ENTITYMANAGER = 20,             /* ENTITYMANAGER  */
  YYSYMBOL_EXPRESSION = 21,                /* EXPRESSION  */
  YYSYMBOL_FILE_P = 22,                    /* FILE_P  */
  YYSYMBOL_FILEDESCRIPTOR = 23,            /* FILEDESCRIPTOR  */
  YYSYMBOL_FILEINPUTSTREAM = 24,           /* FILEINPUTSTREAM  */
  YYSYMBOL_FILEOUTPUTSTREAM = 25,          /* FILEOUTPUTSTREAM  */
  YYSYMBOL_FILEPERMISSION = 26,            /* FILEPERMISSION  */
  YYSYMBOL_FILEREADER = 27,                /* FILEREADER  */
  YYSYMBOL_FILEWRITER = 28,                /* FILEWRITER  */
  YYSYMBOL_FILTERINPUTSTREAM = 29,         /* FILTERINPUTSTREAM  */
  YYSYMBOL_FILTEROUTPUTSTREAM = 30,        /* FILTEROUTPUTSTREAM  */
  YYSYMBOL_FILTERREADER = 31,              /* FILTERREADER  */
  YYSYMBOL_INHERITABLETHREADLOCAL = 32,    /* INHERITABLETHREADLOCAL  */
  YYSYMBOL_INPUTSTREAM = 33,               /* INPUTSTREAM  */
  YYSYMBOL_INPUTSTREAMREADER = 34,         /* INPUTSTREAMREADER  */
  YYSYMBOL_INTEGER = 35,                   /* INTEGER  */
  YYSYMBOL_IO = 36,                        /* IO  */
  YYSYMBOL_JAVA = 37,                      /* JAVA  */
  YYSYMBOL_JAVAX = 38,                     /* JAVAX  */
  YYSYMBOL_LANG = 39,                      /* LANG  */
  YYSYMBOL_LINENUMBERREADER = 40,          /* LINENUMBERREADER  */
  YYSYMBOL_MEMBERACCESS = 41,              /* MEMBERACCESS  */
  YYSYMBOL_MESSAGE = 42,                   /* MESSAGE  */
  YYSYMBOL_MISC = 43,                      /* MISC  */
  YYSYMBOL_NEW = 44,                       /* NEW  */
  YYSYMBOL_NOT = 45,                       /* NOT  */
  YYSYMBOL_NUMBER = 46,                    /* NUMBER  */
  YYSYMBOL_OBJECT = 47,                    /* OBJECT  */
  YYSYMBOL_OBJECTOUTPUTSTREAM = 48,        /* OBJECTOUTPUTSTREAM  */
  YYSYMBOL_OGNL = 49,                      /* OGNL  */
  YYSYMBOL_OGNLCONTEXT = 50,               /* OGNLCONTEXT  */
  YYSYMBOL_OR = 51,                        /* OR  */
  YYSYMBOL_OUTPUTSTREAM = 52,              /* OUTPUTSTREAM  */
  YYSYMBOL_PACKAGE = 53,                   /* PACKAGE  */
  YYSYMBOL_PERSISTENCE = 54,               /* PERSISTENCE  */
  YYSYMBOL_PIPEDOUTPUTSTREAM = 55,         /* PIPEDOUTPUTSTREAM  */
  YYSYMBOL_PIPEDREADER = 56,               /* PIPEDREADER  */
  YYSYMBOL_PRINTSTREAM = 57,               /* PRINTSTREAM  */
  YYSYMBOL_PROCESS = 58,                   /* PROCESS  */
  YYSYMBOL_PROCESSBUILDER = 59,            /* PROCESSBUILDER  */
  YYSYMBOL_PUSHBACKINPUTSTREAM = 60,       /* PUSHBACKINPUTSTREAM  */
  YYSYMBOL_READER = 61,                    /* READER  */
  YYSYMBOL_REFLECT = 62,                   /* REFLECT  */
  YYSYMBOL_RUNTIME = 63,                   /* RUNTIME  */
  YYSYMBOL_RUNTIMEPERMISSION = 64,         /* RUNTIMEPERMISSION  */
  YYSYMBOL_SCANNER = 65,                   /* SCANNER  */
  YYSYMBOL_SCRIPT = 66,                    /* SCRIPT  */
  YYSYMBOL_SCRIPTENGINEMANAGE = 67,        /* SCRIPTENGINEMANAGE  */
  YYSYMBOL_SECURITYMANAGER = 68,           /* SECURITYMANAGER  */
  YYSYMBOL_SERVLET = 69,                   /* SERVLET  */
  YYSYMBOL_SERVLETCONTEXT = 70,            /* SERVLETCONTEXT  */
  YYSYMBOL_SHUTDOWN = 71,                  /* SHUTDOWN  */
  YYSYMBOL_STRING = 72,                    /* STRING  */
  YYSYMBOL_STRINGBUILDER = 73,             /* STRINGBUILDER  */
  YYSYMBOL_STRINGREADER = 74,              /* STRINGREADER  */
  YYSYMBOL_SUN = 75,                       /* SUN  */
  YYSYMBOL_SYSTEM = 76,                    /* SYSTEM  */
  YYSYMBOL_THREAD = 77,                    /* THREAD  */
  YYSYMBOL_THREADGROUP = 78,               /* THREADGROUP  */
  YYSYMBOL_THREADLOCAL = 79,               /* THREADLOCAL  */
  YYSYMBOL_TYPE = 80,                      /* TYPE  */
  YYSYMBOL_UNSAFE = 81,                    /* UNSAFE  */
  YYSYMBOL_UTIL = 82,                      /* UTIL  */
  YYSYMBOL_XMLDECODE = 83,                 /* XMLDECODE  */
  YYSYMBOL_XOR = 84,                       /* XOR  */
  YYSYMBOL_EXPRESSION_START = 85,          /* EXPRESSION_START  */
  YYSYMBOL_EXPRESSION_END = 86,            /* EXPRESSION_END  */
  YYSYMBOL_DOT_DOT = 87,                   /* DOT_DOT  */
  YYSYMBOL_NOT_EQUAL = 88,                 /* NOT_EQUAL  */
  YYSYMBOL_EQUAL = 89,                     /* EQUAL  */
  YYSYMBOL_LESS_EQUAL = 90,                /* LESS_EQUAL  */
  YYSYMBOL_GREATER_EQUAL = 91,             /* GREATER_EQUAL  */
  YYSYMBOL_AND_AND = 92,                   /* AND_AND  */
  YYSYMBOL_OR_OR = 93,                     /* OR_OR  */
  YYSYMBOL_ICONST = 94,                    /* ICONST  */
  YYSYMBOL_BCONST = 95,                    /* BCONST  */
  YYSYMBOL_XCONST = 96,                    /* XCONST  */
  YYSYMBOL_SCONST = 97,                    /* SCONST  */
  YYSYMBOL_USCONST = 98,                   /* USCONST  */
  YYSYMBOL_FCONST = 99,                    /* FCONST  */
  YYSYMBOL_IDENT = 100,                    /* IDENT  */
  YYSYMBOL_UIDENT = 101,                   /* UIDENT  */
  YYSYMBOL_102_ = 102,                     /* ','  */
  YYSYMBOL_103_ = 103,                     /* '.'  */
  YYSYMBOL_104_ = 104,                     /* '='  */
  YYSYMBOL_105_ = 105,                     /* '&'  */
  YYSYMBOL_106_ = 106,                     /* '('  */
  YYSYMBOL_107_ = 107,                     /* ')'  */
  YYSYMBOL_108_ = 108,                     /* '-'  */
  YYSYMBOL_109_ = 109,                     /* ':'  */
  YYSYMBOL_110_ = 110,                     /* '#'  */
  YYSYMBOL_111___ = 111,                   /* '_'  */
  YYSYMBOL_112_ = 112,                     /* '['  */
  YYSYMBOL_113_ = 113,                     /* ']'  */
  YYSYMBOL_114_ = 114,                     /* '@'  */
  YYSYMBOL_YYACCEPT = 115,                 /* $accept  */
  YYSYMBOL_parse_toplevel = 116,           /* parse_toplevel  */
  YYSYMBOL_ognl_sentence = 117,            /* ognl_sentence  */
  YYSYMBOL_sentence = 118,                 /* sentence  */
  YYSYMBOL_authority_sentence = 119,       /* authority_sentence  */
  YYSYMBOL_memberaccess_sentence = 120,    /* memberaccess_sentence  */
  YYSYMBOL_context_sentence = 121,         /* context_sentence  */
  YYSYMBOL_context_list = 122,             /* context_list  */
  YYSYMBOL_normal_sentence = 123,          /* normal_sentence  */
  YYSYMBOL_injection_sentence = 124,       /* injection_sentence  */
  YYSYMBOL_new_expr = 125,                 /* new_expr  */
  YYSYMBOL_func_expr_test = 126,           /* func_expr_test  */
  YYSYMBOL_func_expr = 127,                /* func_expr  */
  YYSYMBOL_func_name = 128,                /* func_name  */
  YYSYMBOL_func_list = 129,                /* func_list  */
  YYSYMBOL_java_class_expr = 130,          /* java_class_expr  */
  YYSYMBOL_java_lang_class_expr = 131,     /* java_lang_class_expr  */
  YYSYMBOL_java_io_class_expr = 132,       /* java_io_class_expr  */
  YYSYMBOL_java_util_class_expr = 133,     /* java_util_class_expr  */
  YYSYMBOL_java_lang_class_name = 134,     /* java_lang_class_name  */
  YYSYMBOL_java_io_class_name = 135,       /* java_io_class_name  */
  YYSYMBOL_java_util_class_name = 136      /* java_util_class_name  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Second part of user prologue.  */
#line 34 "../grammar/ognl.y"

#define parser_yyerror(msg) scanner_yyerror(msg)
static void base_yyerror(YYLTYPE *yylloc, int *token_list, int *token_index, int *last_errindex, /*for error recovery*/ const char *msg);

#line 270 "ognl.tab.c"


#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  21
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   190

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  115
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  187

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   356


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,   110,     2,     2,   105,     2,
     106,   107,     2,     2,   102,   108,   103,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   109,     2,
       2,   104,     2,     2,   114,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   112,     2,   113,     2,   111,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    57,    57,    59,    60,    61,    62,    63,    66,    67,
      68,    71,    72,    73,    76,    77,    78,    79,    82,    85,
      88,    91,    92,    93,    94,    95,    97,    98,   101,   102,
     105,   108,   111,   112,   113,   114,   117,   118,   119,   120,
     121,   122,   123,   124,   127,   130,   133,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   188,   189
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "AND", "BEANS",
  "BUFFEREDINPUTSTREAM", "BUFFEREDREADER", "BYTEARRAYINPUTSTREAM",
  "BYTEARRAYOUTPUTSTREAM", "CHARARRAYREADER", "CLASS", "CLASSLOADER",
  "COLLECTIONS", "COMMAND", "COMPILER", "CONTENT", "CONTEXT",
  "DATAINPUTSTREAM", "DEBUG", "DEFAULT_MEMBER_ACCESS", "ENTITYMANAGER",
  "EXPRESSION", "FILE_P", "FILEDESCRIPTOR", "FILEINPUTSTREAM",
  "FILEOUTPUTSTREAM", "FILEPERMISSION", "FILEREADER", "FILEWRITER",
  "FILTERINPUTSTREAM", "FILTEROUTPUTSTREAM", "FILTERREADER",
  "INHERITABLETHREADLOCAL", "INPUTSTREAM", "INPUTSTREAMREADER", "INTEGER",
  "IO", "JAVA", "JAVAX", "LANG", "LINENUMBERREADER", "MEMBERACCESS",
  "MESSAGE", "MISC", "NEW", "NOT", "NUMBER", "OBJECT",
  "OBJECTOUTPUTSTREAM", "OGNL", "OGNLCONTEXT", "OR", "OUTPUTSTREAM",
  "PACKAGE", "PERSISTENCE", "PIPEDOUTPUTSTREAM", "PIPEDREADER",
  "PRINTSTREAM", "PROCESS", "PROCESSBUILDER", "PUSHBACKINPUTSTREAM",
  "READER", "REFLECT", "RUNTIME", "RUNTIMEPERMISSION", "SCANNER", "SCRIPT",
  "SCRIPTENGINEMANAGE", "SECURITYMANAGER", "SERVLET", "SERVLETCONTEXT",
  "SHUTDOWN", "STRING", "STRINGBUILDER", "STRINGREADER", "SUN", "SYSTEM",
  "THREAD", "THREADGROUP", "THREADLOCAL", "TYPE", "UNSAFE", "UTIL",
  "XMLDECODE", "XOR", "EXPRESSION_START", "EXPRESSION_END", "DOT_DOT",
  "NOT_EQUAL", "EQUAL", "LESS_EQUAL", "GREATER_EQUAL", "AND_AND", "OR_OR",
  "ICONST", "BCONST", "XCONST", "SCONST", "USCONST", "FCONST", "IDENT",
  "UIDENT", "','", "'.'", "'='", "'&'", "'('", "')'", "'-'", "':'", "'#'",
  "'_'", "'['", "']'", "'@'", "$accept", "parse_toplevel", "ognl_sentence",
  "sentence", "authority_sentence", "memberaccess_sentence",
  "context_sentence", "context_list", "normal_sentence",
  "injection_sentence", "new_expr", "func_expr_test", "func_expr",
  "func_name", "func_list", "java_class_expr", "java_lang_class_expr",
  "java_io_class_expr", "java_util_class_expr", "java_lang_class_name",
  "java_io_class_name", "java_util_class_name", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-92)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -14,   -91,   -84,   -79,   -41,   -41,    31,   -92,   -47,    26,
     -66,   -92,   -16,   -28,   -44,   -59,   -92,   -92,   -92,   -28,
     -63,   -92,   -64,   -57,   -41,   -61,   -51,    13,   -48,   -46,
     -45,   -87,   -92,   -92,   -92,   -92,   -38,   -55,   -42,   -22,
      39,   -39,   -35,    18,   -82,    -2,   -43,    23,   -30,   -30,
     -25,   -92,   -92,   -92,   -30,   -21,   -41,   -26,   -92,   -92,
     -32,   -28,   -17,   -20,    -9,   -10,    -5,    -3,     9,    12,
      14,    15,    16,   -92,   -92,    20,    -7,   -92,   -13,   -92,
      17,    30,   -41,    22,   -85,    25,   -23,    21,    44,    80,
     111,    60,    -4,   113,    64,    57,   -30,   -62,   -30,    33,
     -92,   -92,    42,   -30,   -30,    45,    34,    35,    40,   -92,
     -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,
     -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,
     -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,
     -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,
     -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,
     -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,
     -92,    43,   -92,    47,   -92,   -92,   -92,   -92,    51,    52,
      53,   -92,    48,   -92,   -92,   -92,   -92
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,    27,    27,     0,     2,     0,     0,
       0,    26,     0,     0,     0,     0,    11,    12,     8,     0,
       0,     1,     0,     0,    27,     0,     0,     0,     0,     0,
       0,     0,    36,    37,    38,     3,    27,     0,     0,     0,
       0,     0,     0,    27,     0,     0,     0,     0,     0,     0,
       0,    10,    13,     9,     0,     0,    27,     0,     7,    19,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    31,    22,    28,     0,    21,     0,    25,
       0,     0,    27,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    32,     0,     0,
       6,     4,     0,     0,     0,     0,     0,     0,     0,    43,
      77,    75,    79,    78,    80,    76,    68,    69,    70,    71,
      72,    73,    74,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    45,    57,    56,
      58,    61,    63,    64,    59,    60,    50,    49,    65,    47,
      48,    62,    51,    66,    67,    52,    53,    55,    54,    44,
      41,    95,    96,    46,    39,    40,    42,    29,    33,    35,
      34,     0,    20,     0,    18,    24,    23,    14,     0,     0,
       0,    30,     0,    17,    16,    15,     5
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -92,   -92,   -92,     0,   120,   -92,   -92,   -92,   -92,   -92,
     116,   -77,    -8,   -92,   -92,   -12,   -92,   -92,   -92,   -92,
     -92,   -92
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     6,     7,    14,    15,    16,    17,    60,    53,    18,
      19,    74,    75,    76,   171,    31,    32,    33,    34,   159,
     137,   163
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      25,     1,    65,    11,     2,    20,    11,    37,   161,    28,
      29,    70,    28,    29,    28,    29,    48,     8,   103,   167,
       9,    62,    63,    71,    41,    10,   175,    49,     3,   104,
      64,    21,   168,    22,    66,   169,    51,    67,   170,    23,
      24,    77,    35,    36,    38,    39,    79,    30,    40,    84,
      30,    42,    30,    43,    44,    45,    81,    46,    47,    54,
      57,   162,    11,    56,    55,    59,    72,    68,    58,    12,
      73,     4,    12,    13,   107,    78,    50,   106,    82,    80,
      69,    83,   101,    85,    26,   110,   111,   112,   113,   114,
     172,    87,     5,    88,    86,    27,   176,   115,    89,    97,
      90,    98,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    91,   126,   127,    92,   100,    93,    94,    95,
     128,   138,   139,    96,    99,   140,   102,   109,   129,   105,
     160,   165,   130,   164,   108,   131,   132,   133,   166,   173,
     134,   135,   174,   141,   180,   177,   142,   182,   178,   179,
     181,   183,   184,   185,   136,   186,    52,   143,   144,    61,
       0,     0,     0,     0,   145,     0,     0,     0,     0,   146,
     147,     0,     0,   148,   149,   150,     0,     0,     0,   151,
       0,     0,   152,   153,   154,     0,     0,   155,   156,   157,
     158
};

static const yytype_int8 yycheck[] =
{
      16,    15,     4,    44,    18,     5,    44,    19,    12,    37,
      38,    54,    37,    38,    37,    38,   103,   108,   103,    96,
     104,   103,   104,    66,    24,   104,   103,   114,    42,   114,
     112,     0,    94,    80,    36,    97,    36,    39,   100,    13,
     106,    49,    86,   102,   107,   109,    54,    75,   105,    61,
      75,   112,    75,   104,    41,   103,    56,   103,   103,   114,
      21,    65,    44,    85,   106,   100,    43,    69,   107,   110,
     100,    85,   110,   114,    86,   100,   114,   100,   104,   100,
      82,   113,    82,   100,   100,     5,     6,     7,     8,     9,
      98,   100,   106,   103,   114,   111,   104,    17,   103,   106,
     103,   114,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,   103,    33,    34,   103,    86,   103,   103,   103,
      40,    10,    11,   103,   107,    14,   104,    83,    48,   104,
      70,    67,    52,    20,   113,    55,    56,    57,    81,   106,
      60,    61,   100,    32,   104,   100,    35,   100,   114,   114,
     107,   100,   100,   100,    74,   107,    36,    46,    47,    43,
      -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    58,
      59,    -1,    -1,    62,    63,    64,    -1,    -1,    -1,    68,
      -1,    -1,    71,    72,    73,    -1,    -1,    76,    77,    78,
      79
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    15,    18,    42,    85,   106,   116,   117,   108,   104,
     104,    44,   110,   114,   118,   119,   120,   121,   124,   125,
     118,     0,    80,    13,   106,    16,   100,   111,    37,    38,
      75,   130,   131,   132,   133,    86,   102,   130,   107,   109,
     105,   118,   112,   104,    41,   103,   103,   103,   103,   114,
     114,   118,   119,   123,   114,   106,    85,    21,   107,   100,
     122,   125,   103,   104,   112,     4,    36,    39,    69,    82,
      54,    66,    43,   100,   126,   127,   128,   127,   100,   127,
     100,   118,   104,   113,   130,   100,   114,   100,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   106,   114,   107,
      86,   118,   104,   103,   114,   104,   100,   130,   113,    83,
       5,     6,     7,     8,     9,    17,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    33,    34,    40,    48,
      52,    55,    56,    57,    60,    61,    74,   135,    10,    11,
      14,    32,    35,    46,    47,    53,    58,    59,    62,    63,
      64,    68,    71,    72,    73,    76,    77,    78,    79,   134,
      70,    12,    65,   136,    20,    67,    81,   126,    94,    97,
     100,   129,   127,   106,   100,   126,   127,   100,   114,   114,
     104,   107,   100,   100,   100,   100,   107
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   115,   116,   117,   117,   117,   117,   117,   118,   118,
     118,   119,   119,   119,   120,   120,   120,   120,   121,   122,
     123,   124,   124,   124,   124,   124,   125,   125,   126,   126,
     127,   128,   129,   129,   129,   129,   130,   130,   130,   130,
     130,   130,   130,   130,   131,   132,   133,   134,   134,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   135,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     135,   135,   135,   135,   135,   136,   136
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     7,     9,     7,     5,     1,     3,
       3,     1,     1,     3,     7,     8,     8,     8,     7,     1,
       4,     4,     4,     7,     7,     4,     1,     0,     1,     3,
       4,     1,     0,     1,     1,     1,     1,     1,     1,     5,
       5,     5,     5,     5,     5,     5,     5,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (&yylloc, token_list, token_index, last_errindex, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location, token_list, token_index, last_errindex); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, int *token_list, int *token_index, int *last_errindex)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  YY_USE (token_list);
  YY_USE (token_index);
  YY_USE (last_errindex);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, int *token_list, int *token_index, int *last_errindex)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp, token_list, token_index, last_errindex);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule, int *token_list, int *token_index, int *last_errindex)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]), token_list, token_index, last_errindex);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, token_list, token_index, last_errindex); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, int *token_list, int *token_index, int *last_errindex)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  YY_USE (token_list);
  YY_USE (token_index);
  YY_USE (last_errindex);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (int *token_list, int *token_index, int *last_errindex)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval, &yylloc, token_list, token_index);
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {

#line 1499 "ognl.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (&yylloc, token_list, token_index, last_errindex, YY_("syntax error"));
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc, token_list, token_index, last_errindex);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp, token_list, token_index, last_errindex);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, token_list, token_index, last_errindex, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, token_list, token_index, last_errindex);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp, token_list, token_index, last_errindex);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 192 "../grammar/ognl.y"

static void
base_yyerror(YYLTYPE *yylloc, int *token_list, int *token_index, int *last_errindex, const char *msg) /* for error recovery */
{
        parser_yyerror(msg);
}

