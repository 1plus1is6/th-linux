#ifndef TH_PARSER_H
#define TH_PARSER_H
#include "AST.h"
#include "Lexer.h"

typedef struct PARSER_STRUCT
{
    Lexer* lexer;
    Token* token;
} Parser;

Parser* init_Parser(Lexer* lexer);

void eat(Parser* parser, int type);

AST* parse(Parser* parser);

AST* parse_Compound(Parser* parser);

AST* parse_Statement(Parser* parser);

AST* parse_Id(Parser* parser);

AST* parse_Str(Parser* parser);

AST* parse_Var(Parser* parser);

AST* parse_Str_Def(Parser* parser);

AST* parse_Func_Call(Parser* parser);

#endif