#ifndef TH_AST_H
#define TH_AST_H
#include <stdlib.h>

typedef struct AST_STRUCT
{
    enum
    {
        AST_COMPOUND,
        AST_STR,
        AST_VAR,
        AST_STR_DEF,
        AST_FUNC_CALL,
        AST_NOOP
    } type;

    struct AST_STRUCT** compoundValue;
    size_t compoundSize;

    char* strValue;

    char* varName;

    char* strDefName;
    struct AST_STRUCT* strDefValue;

    char* funcCallName;
    struct AST_STRUCT** funcCallArgs;
    size_t funcCallArgsSize;
} AST;

AST* init_AST(int type);

#endif