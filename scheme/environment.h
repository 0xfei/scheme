#ifndef _ENVIRONMENT_H
#define _ENVIRONMENT_H

typedef struct _lable {
    char id;
    struct _lable* next;
} lable;

typedef struct _frame {
    char is_var;
    int  v_type;
    void* value;
    int s_num;
    lable* son;
} frame;

typedef struct _env {
    struct _env* outer;
    frame* vars;
} env;

// create global environment
env* setup_environment(char** vars, void** data);

// new environment
env* create_environment(char** vars, void** data, env* outer);

// lookup variable
void* lookup_variable(char* var, env* environment);

// insert variable
int insert_variable(char* var, void* data, env* environment);

extern env* g_global_environment;

#endif
