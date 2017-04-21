#ifndef _ENVIRONMENT_H
#define _ENVIRONMENT_H

typedef struct _frame {
    int hash;
    char* key;
    int type;
    void* value;
    struct _frame* lson;
    struct _frame* rson;
} frame;

typedef struct _environment {
    struct _environment* upper;
    frame* env;
} environment;

#endif
