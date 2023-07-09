#include "include/Token.h"
#include <stdio.h>
#include <stdlib.h>

Token* init_Token(int type, char* value)
{
    Token* token = malloc(sizeof(struct TOKEN_STRUCT));
    token->type = type;
    token->value = value;

    return token;
}

const char* type_To_Str(int type)
{
    switch (type)
    {
    case 0:
        return "TOKEN_ID";
    
    case 1:
        return "TOKEN_STR";
    
    case 2:
        return "TOKEN_EQUALS";
    
    case 3:
        return "TOKEN_LPAREN";

    case 4:
        return "TOKEN_RPAREN";
    
    case 5:
        return "TOKEN_SEMI";
    
    case 6:
        return "TOKEN_EOF";
    }

    return "<token> error: token not stringable";
}