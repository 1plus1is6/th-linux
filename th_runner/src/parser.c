#include "include/Parser.h"
#include <stdio.h>
#include <string.h>

Parser* init_Parser(Lexer* lexer)
{
    Parser* parser = malloc(sizeof(struct PARSER_STRUCT));
    parser->lexer = lexer;
    parser->token = get_Next_Token(lexer);

    return parser;
}

void eat(Parser* parser, int type)
{
    if (parser->token->type != type)
    {
        printf("<parser> error: unexpected token %s\nexpected %s\n", type_To_Str(parser->token->type), type_To_Str(type));
        exit(1);
    }

    parser->token = get_Next_Token(parser->lexer);
}

AST* parse(Parser* parser)
{
    return parse_Compound(parser);
}

AST* parse_Compound(Parser* parser)
{
    AST* ast = init_AST(AST_COMPOUND);
    ast->compoundValue = calloc(1, sizeof(struct AST_STRUCT*));
    
    AST* statement = parse_Statement(parser);
    ast->compoundValue[ast->compoundSize - 1] = statement;
    ast->compoundSize += 1;

    while (parser->token->type == TOKEN_SEMI)
    {
        eat(parser, TOKEN_SEMI);
        AST* statement = parse_Statement(parser);
        ast->compoundSize += 1;
        ast->compoundValue = realloc(ast->compoundValue, ast->compoundSize * sizeof(struct AST_STRUCT*));
        ast->compoundValue[0] = statement;
    }

    return ast;
}

AST* parse_Statement(Parser* parser)
{
    switch (parser->token->type)
    {
    case TOKEN_ID:
        return parse_Id(parser);

    default: {
        printf("<parser> error: unexpected token %s\n", type_To_Str(parser->token->type));
    }
    }
}

AST* parse_Id(Parser* parser)
{
    if (strcmp(parser->token->value, "str") == 0)
        return parse_Str_Def(parser);
    else
        return parse_Var(parser);  
}

AST* parse_Str(Parser* parser)
{
    AST* ast = init_AST(AST_STR);
    ast->strValue = parser->token->value;
    eat(parser, TOKEN_STR);

    return ast;
}

AST* parse_Var(Parser* parser)
{
    char* value = parser->token->value;
    eat(parser, TOKEN_ID);

    if(parser->token->type == TOKEN_LPAREN)
        return parse_Func_Call(parser);
    
    AST* ast = init_AST(AST_VAR);
    ast->varName = value;

    return ast;
}

AST* parse_Str_Def(Parser* parser)
{
    eat(parser, TOKEN_ID);
    AST* ast = init_AST(AST_STR_DEF);
    ast->strDefName = parser->token->value;
    eat(parser, TOKEN_ID);
    eat(parser, TOKEN_EQUALS);
    ast->strDefValue = parse_Str(parser);

    return ast;
}

AST* parse_Func_Call(Parser* parser)
{
    return init_AST(AST_NOOP);
}