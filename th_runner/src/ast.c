#include "include/AST.h"

AST* init_AST(int type)
{
    AST* ast = malloc(sizeof(struct AST_STRUCT));
    ast->type = type;

    ast->compoundValue = (void*) 0;
    ast->compoundSize = 0;

    ast->strValue = (void*) 0;

    ast->varName = (void*) 0;

    ast->strDefName = (void*) 0;
    ast->strDefValue = (void*) 0;

    ast->funcCallName = (void*) 0;
    ast->funcCallArgs = (void*) 0;
    ast->funcCallArgsSize = 0;

    return ast;
}