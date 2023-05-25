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

%token AND BUFFEREDREADER CLASS CLASSLOADER COLLECTIONS COMMAND COMPILER CONTENT DATAINPUTSTREAM
       DEBUG DEFAULT_MEMBER_ACCESS ENTITYMANAGER EXPRESSION FILE_P FILEDESCRIPTOR FILEINPUTSTREAM
       FILEOUTPUTSTREAM FILEPERMISSION FILEREADER FILEWRITER INHERITABLETHREADLOCAL
       IO JAVA JAVAX LANG MEMBERACCESS MESSAGE MISC NEW NOT OBJECT OGNL OGNLCONTEXT OR 
       PACKAGE PERSISTENCE PROCESS PROCESSBUILDER RUNTIME RUNTIMEPERMISSION SCANNER
       SCRIPT SCRIPTENGINEMANAGE SECURITYMANAGER SERVLET SERVLETCONTEXT SHUTDOWN SUN
       SYSTEM THREAD THREADGROUP THREADLOCAL TYPE UNSAFE UTIL XOR
       EXPRESSION_START EXPRESSION_END DOT_DOT NOT_EQUAL EQUAL LESS_EQUAL GREATER_EQUAL
       AND_AND OR_OR ICONST BCONST XCONST SCONST USCONST FCONST IDENT UIDENT 

%start parse_toplevel

%left ','

%%
parse_toplevel: ognl_sentence;

ognl_sentence : EXPRESSION_START sentence EXPRESSION_END
              | DEBUG '=' COMMAND '&' EXPRESSION '=' sentence 
              | '(' sentence ')''('IDENT')''('IDENT')'
              | CONTENT '-' TYPE ':' EXPRESSION_START sentence EXPRESSION_END
              | MESSAGE '=' '(' sentence ')'
              ;

sentence : injection_sentence
         | authority_sentence ',' normal_sentence
         | authority_sentence ',' injection_sentence
         ;

authority_sentence : memberaccess_sentence ',' context_sentence
                   ;

memberaccess_sentence: /**/;
context_sentence: /**/;

normal_sentence : '@' IDENT '@' func_expr
                ;

injection_sentence : '@' java_class_expr '@' func_expr
                  | '#' IDENT '=' new_expr java_class_expr '@' func_expr
                  | new_expr java_class_expr '@' func_expr
                  ;
new_expr : NEW 
         | /*EMPTY*/
         ;

func_expr : func_name '(' func_list ')'
          ;

func_name : IDENT
          ;

func_list : /* EMPTY */
          | ICONST
          | IDENT
          | SCONST
          ;

java_class_expr : java_lang_class_expr
                | java_io_class_expr
                | java_util_class_expr
                | JAVAX '.' PERSISTENCE '.' ENTITYMANAGER
                | JAVA '.' SCRIPT '.' SCRIPTENGINEMANAGE
                | JAVA '.' SERVLET '.' SERVLETCONTEXT
                | SUN '.' MISC '.' UNSAFE
                ;

java_lang_class_expr : JAVA '.' LANG '.' java_lang_class_name
                     ;

java_io_class_expr : JAVA '.' LANG '.' java_io_class_name
                   ;

java_util_class_expr : JAVA '.' UTIL '.' java_util_class_name
                     ;

java_lang_class_name : RUNTIME
                    | RUNTIMEPERMISSION
                    | PROCESSBUILDER
                    | PROCESS
                    | SHUTDOWN
                    | SYSTEM
                    | THREAD
                    | THREADLOCAL
                    | THREADGROUP
                    | CLASSLOADER
                    | CLASS
                    | COMPILER
                    | OBJECT
                    | PACKAGE
                    | INHERITABLETHREADLOCAL
                    | SECURITYMANAGER
                    ;

java_io_class_name : FILE_P
                   | FILEDESCRIPTOR
                   | FILEINPUTSTREAM
                   | FILEOUTPUTSTREAM
                   | FILEPERMISSION
                   | FILEREADER
                   | FILEWRITER
                   | BUFFEREDREADER
                   | DATAINPUTSTREAM
                   ;

java_util_class_name : COLLECTIONS
                     | SCANNER
                     ;

%%
static void
base_yyerror(YYLTYPE *yylloc, int *token_list, int *token_index, int *last_errindex, const char *msg) /* for error recovery */
{
        parser_yyerror(msg);
}
