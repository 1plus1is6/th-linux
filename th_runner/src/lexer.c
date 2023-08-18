#include "include/Lexer.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

Lexer* init_Lexer(char* src)
{
    Lexer* lexer = malloc(sizeof(struct LEXER_STRUCT));
    lexer->src = src;
    lexer->srcSize = strlen(src);
    lexer->i = 0;
    lexer->c = src[lexer->i];

    return lexer;
}

void advance(Lexer* lexer)
{
    if (lexer->i < lexer->srcSize && lexer->c != '\0')
    {
        lexer->i += 1;
        lexer->c = lexer->src[lexer->i];
    }
}

Token* advance_With_Current(Lexer* lexer, int type)
{
    char* value = calloc(2, sizeof(char));
    value[0] = lexer->c;
    value[1] = '\0';

    advance(lexer);

    return init_Token(type, value);
}

void skip_Whitespace(Lexer* lexer)
{
    while (lexer->c == 13 || lexer->c == 10 || lexer->c == ' ' || lexer->c == '\t')
        advance(lexer);
}

Token* get_Next_Token(Lexer* lexer)
{
    while (lexer->i < lexer->srcSize && lexer->c != '\0')
    {
        skip_Whitespace(lexer);

        if (isalpha(lexer->c))
            return collect_Id(lexer);
        
        if (lexer->c == '"')
            return collect_Str(lexer);
        
        switch (lexer->c)
        {
        case '=':
            return advance_With_Current(lexer, TOKEN_EQUALS);
        
        case '(':
            return advance_With_Current(lexer, TOKEN_LPAREN);
        
        case ')':
            return advance_With_Current(lexer, TOKEN_RPAREN);
        
        case ',':
            return advance_With_Current(lexer, TOKEN_COMMA);
        
        case ';':
            return advance_With_Current(lexer, TOKEN_SEMI);
        
        default: {
            printf("<lexer> error: unknown token \"%c\"\n", lexer->c);
            exit(1);
        }
        }
    }

    return init_Token(TOKEN_EOF, 0);
}

Token* collect_Id(Lexer* lexer)
{
    char* id = calloc(1, sizeof(char));

    while (isalnum(lexer->c))
    {
        id = realloc(id, (strlen(id) + 2) * sizeof(char));
        strcat(id, (char[]){lexer->c, 0});
        advance(lexer);
    }

    return init_Token(TOKEN_ID, id);
}

Token* collect_Str(Lexer* lexer)
{
    advance(lexer);

    char* str = calloc(1, sizeof(char));

    while (lexer->c != '"')
    {
        str = realloc(str, (strlen(str) + 2) * sizeof(char));
        strcat(str, (char[]){lexer->c, 0});
        advance(lexer);
    }

    advance(lexer);

    return init_Token(TOKEN_STR, str);
}