#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#include "../include/ognl-parser.h"
#include "../include/ognl.lex.h"
#include "../include/ognl.tab.h"

typedef struct parser_result
{
    int input_len;
    int *token_info;

} parser_result;

void freeAll( parser_result* final_res )
{
    pfree(final_res->token_info);
    pfree(final_res);
}

parser_result *lexer( char *sentence )
{
    int res;
    int i;
    int max_len = 5000;
    int token_list[max_len];
    int input_len = init_token_list(sentence, token_list, max_len);
    int last_errindex = -100;
    int token_index = 0;
    int *full_token_list = (int *)malloc(sizeof(int) * input_len);
    struct parser_result *final_res = (parser_result *)malloc(sizeof(int) * (input_len + 8));
    for (i=0; i < input_len; i++)
        full_token_list[i] = token_list[i];
    final_res->input_len = input_len;
    final_res->token_info = full_token_list;
    return final_res;
}

int detection( char *sentence )
{
    int res;
    int i;
    int max_len = 5000;
    int token_list[max_len];
    int input_len = init_token_list(sentence, token_list, max_len);
    int last_errindex = -100;
    int token_index = 0;
    while (token_index < input_len)
    {
        res = base_yyparse(token_list, &token_index, &last_errindex);
        // printf("res1 = %d\n",res);
        if( res == 1 ) return 1;
    }
    return res;
}


int main()
{
    return 0;
}
