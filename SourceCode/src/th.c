#include "include/TH.h"
#include <stdio.h>
#include "include/IO.h"
#include "include/Lexer.h"

void run(char* src)
{
    Lexer* lexer = init_Lexer(src);
    Token* token = 0;

    while ((token = get_Next_Token(lexer))->type != TOKEN_EOF)
        printf("TOKEN(%s, \"%s\")\n", type_To_Str(token->type), token->value);
}

void run_File(const char* filename)
{
    char* src = read_File(filename);
    run(src);
    free(src);
}