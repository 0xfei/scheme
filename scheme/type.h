#ifndef _TYPE_H
#define _TYPE_H

typedef enum _s_type {
    TYPE_CALL,      // ( )
    TYPE_OPERATOR,  // + - * / ...
    TYPE_CONS,      // cons car cdr set-car! set-cdr!
    TYPE_DEFINE,    // define
    TYPE_LAMBDA,    // lambda
    TYPE_LIST,      // list
    TYPE_VARIABLE,  // variable
} s_type;

typedef struct _variable {
    int len;
    char* data;
} variable;


#endif
