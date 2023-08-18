#ifndef TH_LEXER_H
#define TH_LEXER_H
#include <stdlib.h>
#include "Token.h"

typedef struct LEXER_STRUCT
{
    char* src;
    size_t srcSize;
    unsigned int i;
    char c;
} Lexer;

Lexer* init_Lexer(char* src);

void advance(Lexer* lexer);

Token* advance_With_Current(Lexer* lexer, int type);

void skip_Whitespace(Lexer* lexer);

Token* get_Next_Token(Lexer* lexer);

Token* collect_Id(Lexer* lexer);

Token* collect_Str(Lexer* lexer);

#endif