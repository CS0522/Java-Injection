%{
#define YYDEBUG 1
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "../include/ognl-parser.h"
#include "../include/ognl.tab.h"

#define YYLLOC_DEFAULT(Current, Rhs, N) \
        do { \
                if ((N) > 0) \
                        (Current) = (Rhs)[1]; \
                else \
                        (Current) = (-1); \
        } while (0)
#define YYMALLOC palloc
#define YYFREE   pfree
%}

%expect 0
%name-prefix="base_yy"
%define api.pure
%locations
%parse-param {int *token_list}{int *token_index}{int *last_errindex} /*for error recovery*/
%lex-param {int *token_list}{int *token_index}
%code requires {char *filename;}

%union {
    core_YYSTYPE core_yystype;
    int ival; /* for integer literals */
    char *str; /* for identifiers and non-integer literals */
    const char *keyword; /* canonical spelling of keywords */
}

%{
#define parser_yyerror(msg) scanner_yyerror(msg)
static void base_yyerror(YYLTYPE *yylloc, int *token_list, int *token_index, int *last_errindex, /*for error recovery*/ const char *msg);
%}

%token AND BUFFEREDREADER CLASS CLASSLOADER COLLECTIONS COMPILER DATAINPUTSTREAM
       DEFAULT_MEMBER_ACCESS ENTITYMANAGER FILE_P FILEDESCRIPTOR FILEINPUTSTREAM
       FILEOUTPUTSTREAM FILEPERMISSION FILEREADER FILEWRITER INHERITABLETHREADLOCAL
       IO JAVA JAVAX LANG MEMBERACCESS MISC NEW NOT OBJECT OGNL OGNLCONTEXT OR 
       PACKAGE PERSISTENCE PROCESS PROCESSBUILDER RUNTIME RUNTIMEPERMISSION SCANNER
       SCRIPT SCRIPTENGINEMANAGE SECURITYMANAGER SERVLET SERVLETCONTEXT SHUTDOWN SUN
       SYSTEM THREAD THREADGROUP THREADLOCAL UNSAFE UTIL XOR
       EXPRESSION_START EXPRESSION_END DOT_DOT NOT_EQUAL EQUAL LESS_EQUAL GREATER_EQUAL
       AND_AND OR_OR ICONST BCONST XCONST SCONST USCONST FCONST IDENT UIDENT 

%start parse_toplevel

%%

parse_toplevel: EXPRESSION_START sentence EXPRESSION_END
               ;

sentence: ;
%%
static void
base_yyerror(YYLTYPE *yylloc, int *token_list, int *token_index, int *last_errindex, const char *msg) /* for error recovery */
{
        parser_yyerror(msg);
}

