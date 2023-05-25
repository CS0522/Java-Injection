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
/* "%code requires" blocks.  */
#line 26 "grammar/ognl.y"
char *filename;

#line 52 "ognl.tab.h"

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
    BUFFEREDREADER = 259,          /* BUFFEREDREADER  */
    CLASS = 260,                   /* CLASS  */
    CLASSLOADER = 261,             /* CLASSLOADER  */
    COLLECTIONS = 262,             /* COLLECTIONS  */
    COMPILER = 263,                /* COMPILER  */
    DATAINPUTSTREAM = 264,         /* DATAINPUTSTREAM  */
    DEFAULT_MEMBER_ACCESS = 265,   /* DEFAULT_MEMBER_ACCESS  */
    ENTITYMANAGER = 266,           /* ENTITYMANAGER  */
    FILE_P = 267,                  /* FILE_P  */
    FILEDESCRIPTOR = 268,          /* FILEDESCRIPTOR  */
    FILEINPUTSTREAM = 269,         /* FILEINPUTSTREAM  */
    FILEOUTPUTSTREAM = 270,        /* FILEOUTPUTSTREAM  */
    FILEPERMISSION = 271,          /* FILEPERMISSION  */
    FILEREADER = 272,              /* FILEREADER  */
    FILEWRITER = 273,              /* FILEWRITER  */
    INHERITABLETHREADLOCAL = 274,  /* INHERITABLETHREADLOCAL  */
    IO = 275,                      /* IO  */
    JAVA = 276,                    /* JAVA  */
    JAVAX = 277,                   /* JAVAX  */
    LANG = 278,                    /* LANG  */
    MEMBERACCESS = 279,            /* MEMBERACCESS  */
    MISC = 280,                    /* MISC  */
    NEW = 281,                     /* NEW  */
    NOT = 282,                     /* NOT  */
    OBJECT = 283,                  /* OBJECT  */
    OGNL = 284,                    /* OGNL  */
    OGNLCONTEXT = 285,             /* OGNLCONTEXT  */
    OR = 286,                      /* OR  */
    PACKAGE = 287,                 /* PACKAGE  */
    PERSISTENCE = 288,             /* PERSISTENCE  */
    PROCESS = 289,                 /* PROCESS  */
    PROCESSBUILDER = 290,          /* PROCESSBUILDER  */
    RUNTIME = 291,                 /* RUNTIME  */
    RUNTIMEPERMISSION = 292,       /* RUNTIMEPERMISSION  */
    SCANNER = 293,                 /* SCANNER  */
    SCRIPT = 294,                  /* SCRIPT  */
    SCRIPTENGINEMANAGE = 295,      /* SCRIPTENGINEMANAGE  */
    SECURITYMANAGER = 296,         /* SECURITYMANAGER  */
    SERVLET = 297,                 /* SERVLET  */
    SERVLETCONTEXT = 298,          /* SERVLETCONTEXT  */
    SHUTDOWN = 299,                /* SHUTDOWN  */
    SUN = 300,                     /* SUN  */
    SYSTEM = 301,                  /* SYSTEM  */
    THREAD = 302,                  /* THREAD  */
    THREADGROUP = 303,             /* THREADGROUP  */
    THREADLOCAL = 304,             /* THREADLOCAL  */
    UNSAFE = 305,                  /* UNSAFE  */
    UTIL = 306,                    /* UTIL  */
    XOR = 307,                     /* XOR  */
    EXPRESSION_START = 308,        /* EXPRESSION_START  */
    EXPRESSION_END = 309,          /* EXPRESSION_END  */
    DOT_DOT = 310,                 /* DOT_DOT  */
    NOT_EQUAL = 311,               /* NOT_EQUAL  */
    EQUAL = 312,                   /* EQUAL  */
    LESS_EQUAL = 313,              /* LESS_EQUAL  */
    GREATER_EQUAL = 314,           /* GREATER_EQUAL  */
    AND_AND = 315,                 /* AND_AND  */
    OR_OR = 316,                   /* OR_OR  */
    ICONST = 317,                  /* ICONST  */
    BCONST = 318,                  /* BCONST  */
    XCONST = 319,                  /* XCONST  */
    SCONST = 320,                  /* SCONST  */
    USCONST = 321,                 /* USCONST  */
    FCONST = 322,                  /* FCONST  */
    IDENT = 323,                   /* IDENT  */
    UIDENT = 324                   /* UIDENT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 28 "grammar/ognl.y"

    core_YYSTYPE core_yystype;
    int ival; /* for integer literals */
    char *str; /* for identifiers and non-integer literals */
    const char *keyword; /* canonical spelling of keywords */

#line 145 "ognl.tab.h"

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
