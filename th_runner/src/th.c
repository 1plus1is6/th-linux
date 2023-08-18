#include "include/TH.h"
#include <stdio.h>
#include "include/Parser.h"
#include "include/IO.h"

void run(char* src)
{
    Lexer* lexer = init_Lexer(src);
    Parser* parser = init_Parser(lexer);
    AST* ast = parse(parser);

    printf("%d\n", ast->type);

    free(lexer);
}

void run_File(const char* filename)
{
    char* src = read_File(filename);
    run(src);
    free(src);
}