/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_BASE_YY_OGNL_TAB_H_INCLUDED
# define YY_BASE_YY_OGNL_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int base_yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    AND = 258,                     /* AND  */
    BEANS = 259,                   /* BEANS  */
    BUFFEREDINPUTSTREAM = 260,     /* BUFFEREDINPUTSTREAM  */
    BUFFEREDREADER = 261,          /* BUFFEREDREADER  */
    BYTEARRAYINPUTSTREAM = 262,    /* BYTEARRAYINPUTSTREAM  */
    BYTEARRAYOUTPUTSTREAM = 263,   /* BYTEARRAYOUTPUTSTREAM  */
    CHARARRAYREADER = 264,         /* CHARARRAYREADER  */
    CLASS = 265,                   /* CLASS  */
    CLASSLOADER = 266,             /* CLASSLOADER  */
    COLLECTIONS = 267,             /* COLLECTIONS  */
    COMMAND = 268,                 /* COMMAND  */
    COMPILER = 269,                /* COMPILER  */
    CONTENT = 270,                 /* CONTENT  */
    CONTEXT = 271,                 /* CONTEXT  */
    DATAINPUTSTREAM = 272,         /* DATAINPUTSTREAM  */
    DEBUG = 273,                   /* DEBUG  */
    DEFAULT_MEMBER_ACCESS = 274,   /* DEFAULT_MEMBER_ACCESS  */
    ENTITYMANAGER = 275,           /* ENTITYMANAGER  */
    EXPRESSION = 276,              /* EXPRESSION  */
    FILE_P = 277,                  /* FILE_P  */
    FILEDESCRIPTOR = 278,          /* FILEDESCRIPTOR  */
    FILEINPUTSTREAM = 279,         /* FILEINPUTSTREAM  */
    FILEOUTPUTSTREAM = 280,        /* FILEOUTPUTSTREAM  */
    FILEPERMISSION = 281,          /* FILEPERMISSION  */
    FILEREADER = 282,              /* FILEREADER  */
    FILEWRITER = 283,              /* FILEWRITER  */
    FILTERINPUTSTREAM = 284,       /* FILTERINPUTSTREAM  */
    FILTEROUTPUTSTREAM = 285,      /* FILTEROUTPUTSTREAM  */
    FILTERREADER = 286,            /* FILTERREADER  */
    INHERITABLETHREADLOCAL = 287,  /* INHERITABLETHREADLOCAL  */
    INPUTSTREAM = 288,             /* INPUTSTREAM  */
    INPUTSTREAMREADER = 289,       /* INPUTSTREAMREADER  */
    INTEGER = 290,                 /* INTEGER  */
    IO = 291,                      /* IO  */
    JAVA = 292,                    /* JAVA  */
    JAVAX = 293,                   /* JAVAX  */
    LANG = 294,                    /* LANG  */
    LINENUMBERREADER = 295,        /* LINENUMBERREADER  */
    MEMBERACCESS = 296,            /* MEMBERACCESS  */
    MESSAGE = 297,                 /* MESSAGE  */
    MISC = 298,                    /* MISC  */
    NEW = 299,                     /* NEW  */
    NOT = 300,                     /* NOT  */
    NUMBER = 301,                  /* NUMBER  */
    OBJECT = 302,                  /* OBJECT  */
    OBJECTOUTPUTSTREAM = 303,      /* OBJECTOUTPUTSTREAM  */
    OGNL = 304,                    /* OGNL  */
    OGNLCONTEXT = 305,             /* OGNLCONTEXT  */
    OR = 306,                      /* OR  */
    OUTPUTSTREAM = 307,            /* OUTPUTSTREAM  */
    PACKAGE = 308,                 /* PACKAGE  */
    PERSISTENCE = 309,             /* PERSISTENCE  */
    PIPEDOUTPUTSTREAM = 310,       /* PIPEDOUTPUTSTREAM  */
    PIPEDREADER = 311,             /* PIPEDREADER  */
    PRINTSTREAM = 312,             /* PRINTSTREAM  */
    PROCESS = 313,                 /* PROCESS  */
    PROCESSBUILDER = 314,          /* PROCESSBUILDER  */
    PUSHBACKINPUTSTREAM = 315,     /* PUSHBACKINPUTSTREAM  */
    READER = 316,                  /* READER  */
    REFLECT = 317,                 /* REFLECT  */
    RUNTIME = 318,                 /* RUNTIME  */
    RUNTIMEPERMISSION = 319,       /* RUNTIMEPERMISSION  */
    SCANNER = 320,                 /* SCANNER  */
    SCRIPT = 321,                  /* SCRIPT  */
    SCRIPTENGINEMANAGE = 322,      /* SCRIPTENGINEMANAGE  */
    SECURITYMANAGER = 323,         /* SECURITYMANAGER  */
    SERVLET = 324,                 /* SERVLET  */
    SERVLETCONTEXT = 325,          /* SERVLETCONTEXT  */
    SHUTDOWN = 326,                /* SHUTDOWN  */
    STRING = 327,                  /* STRING  */
    STRINGBUILDER = 328,           /* STRINGBUILDER  */
    STRINGREADER = 329,            /* STRINGREADER  */
    SUN = 330,                     /* SUN  */
    SYSTEM = 331,                  /* SYSTEM  */
    THREAD = 332,                  /* THREAD  */
    THREADGROUP = 333,             /* THREADGROUP  */
    THREADLOCAL = 334,             /* THREADLOCAL  */
    TYPE = 335,                    /* TYPE  */
    UNSAFE = 336,                  /* UNSAFE  */
    UTIL = 337,                    /* UTIL  */
    XMLDECODE = 338,               /* XMLDECODE  */
    XOR = 339,                     /* XOR  */
    EXPRESSION_START = 340,        /* EXPRESSION_START  */
    EXPRESSION_END = 341,          /* EXPRESSION_END  */
    DOT_DOT = 342,                 /* DOT_DOT  */
    NOT_EQUAL = 343,               /* NOT_EQUAL  */
    EQUAL = 344,                   /* EQUAL  */
    LESS_EQUAL = 345,              /* LESS_EQUAL  */
    GREATER_EQUAL = 346,           /* GREATER_EQUAL  */
    AND_AND = 347,                 /* AND_AND  */
    OR_OR = 348,                   /* OR_OR  */
    ICONST = 349,                  /* ICONST  */
    BCONST = 350,                  /* BCONST  */
    XCONST = 351,                  /* XCONST  */
    SCONST = 352,                  /* SCONST  */
    USCONST = 353,                 /* USCONST  */
    FCONST = 354,                  /* FCONST  */
    IDENT = 355,                   /* IDENT  */
    UIDENT = 356                   /* UIDENT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 27 "grammar/ognl.y"

    core_YYSTYPE core_yystype;
    int ival; /* for integer literals */
    char *str; /* for identifiers and non-integer literals */
    const char *keyword; /* canonical spelling of keywords */

#line 172 "ognl.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif




int base_yyparse (int *token_list, int *token_index, int *last_errindex);


#endif /* !YY_BASE_YY_OGNL_TAB_H_INCLUDED  */
