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

%token AND BEANS BUFFEREDINPUTSTREAM BUFFEREDREADER BYTEARRAYINPUTSTREAM BYTEARRAYOUTPUTSTREAM
       CHARARRAYREADER CLASS CLASSLOADER COLLECTIONS COMMAND COMPILER CONTENT CONTEXT DATAINPUTSTREAM
       DEBUG DEFAULT_MEMBER_ACCESS ENTITYMANAGER EXPRESSION FILE_P FILEDESCRIPTOR FILEINPUTSTREAM
       FILEOUTPUTSTREAM FILEPERMISSION FILEREADER FILEWRITER FILTERINPUTSTREAM FILTEROUTPUTSTREAM
       FILTERREADER FILTERWRITER INHERITABLETHREADLOCAL INPUTSTREAM INPUTSTREAMREADER INTEGER IO JAVA
       JAVAX LANG LINENUMBERREADER MEMBERACCESS MESSAGE MISC NEW NOT NUMBER OBJECT OBJECTOUTPUTSTREAM
       OGNL OGNLCONTEXT OR OUTPUTSTREAM PACKAGE PERSISTENCE PIPEDOUTPUTSTREAM PIPEDREADER PRINTSTREAM
       PROCESS PROCESSBUILDER PUSHBACKINPUTSTREAM RANDOMACCESSFILE READER REFLECT RUNTIME RUNTIMEPERMISSION SCANNER
       SCRIPT SCRIPTENGINEMANAGE SECURITYMANAGER SERVLET SERVLETCONTEXT SHUTDOWN STRING  STRINGBUILDER
       STRINGREADER SUN SYSTEM THREAD THREADGROUP THREADLOCAL TYPE UNSAFE UTIL XMLDECODE XOR
       EXPRESSION_START EXPRESSION_END DOT_DOT NOT_EQUAL EQUAL LESS_EQUAL GREATER_EQUAL
       AND_AND OR_OR ICONST BCONST XCONST SCONST USCONST FCONST IDENT UIDENT 

%start parse_toplevel

%left ',' '.'

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

authority_sentence : memberaccess_sentence 
                   | context_sentence
                   | authority_sentence ',' authority_sentence 
                   | authority_sentence ',' dirty_sentence
                   | dirty_sentence ',' authority_sentence
                   ;

memberaccess_sentence : '#' '_' MEMBERACCESS '.' IDENT '=' IDENT
                      | '#' '_' MEMBERACCESS '[' IDENT ']' '=' IDENT
                      | '#' '_' MEMBERACCESS '=' '@' java_class_expr '@' IDENT 
                      | '#' '_' MEMBERACCESS '=' '@' IDENT '@' IDENT 
                      | '#' '_' MEMBERACCESS '=' '@' DEFAULT_MEMBER_ACCESS 
                      | '#' '_' MEMBERACCESS '.' func_expr
                      | '#' IDENT '=' '_' MEMBERACCESS '.' func_expr
                      ;

context_sentence : '#' CONTEXT '[' context_list ']' '=' IDENT
                 ;

context_list : IDENT 
             ;

normal_sentence : '@' IDENT '@' func_expr
                ;

dirty_sentence : dirty_char
               | dirty_sentence dirty_char
               ;

dirty_char : IDENT
           | ICONST
           | FCONST
           | dirty_op
           | SCONST
           ;

dirty_op : '+'
         | '-' 
         | '*'
         | '&'
         ;

injection_sentence : preclass_expr java_class_expr '@' func_expr
                  | preclass_expr java_class_expr '.' func_expr
                  | '#' IDENT '=' preclass_expr java_class_expr '@' func_expr
                  | '#' IDENT '=' preclass_expr java_class_expr '.' func_expr
                  | injection_sentence ',' execute_sentence
                  | injection_sentence ',' dirty_sentence
                  ;

execute_sentence : '#' IDENT '.' func_expr
                 | '#' IDENT '=' execute_sentence
                 ;

preclass_expr : NEW 
              | /*EMPTY*/
              | '@'
              ;
 
func_expr : func_name '(' func_list ')' 
          | func_expr '.' func_expr
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
                | JAVAX '.' PERSISTENCE '.' PERSISTENCE
                | JAVAX '.' SCRIPT '.' SCRIPTENGINEMANAGE
                | JAVAX '.' SERVLET '.' SERVLETCONTEXT
                | SUN '.' MISC '.' UNSAFE
                | JAVA '.' BEANS '.' XMLDECODE
                ;

java_lang_class_expr : JAVA '.' LANG '.' java_lang_class_name
                     ;

java_io_class_expr : JAVA '.' IO '.' java_io_class_name
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
                    | INTEGER
                    | NUMBER
                    | REFLECT
                    | STRING
                    | STRINGBUILDER
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
                   | BUFFEREDINPUTSTREAM
                   | BYTEARRAYOUTPUTSTREAM
                   | BYTEARRAYINPUTSTREAM
                   | CHARARRAYREADER
                   | FILTERINPUTSTREAM
                   | FILTEROUTPUTSTREAM
                   | FILTERREADER
                   | FILTERWRITER
                   | INPUTSTREAM
                   | INPUTSTREAMREADER
                   | LINENUMBERREADER
                   | OBJECTOUTPUTSTREAM
                   | OUTPUTSTREAM
                   | PIPEDOUTPUTSTREAM
                   | PIPEDREADER
                   | PRINTSTREAM
                   | PUSHBACKINPUTSTREAM
                   | READER
                   | STRINGREADER
                   | RANDOMACCESSFILE
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

