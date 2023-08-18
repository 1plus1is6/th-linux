#ifndef TH_TOKEN_H
#define TH_TOKEN_H

typedef struct TOKEN_STRUCT
{
    enum
    {
        TOKEN_ID,
        TOKEN_STR,
        TOKEN_EQUALS,
        TOKEN_LPAREN,
        TOKEN_RPAREN,
        TOKEN_COMMA,
        TOKEN_SEMI,
        TOKEN_EOF
    } type;
    
    char* value;
} Token;

Token* init_Token(int type, char* value);

const char* type_To_Str(int type);

#endif