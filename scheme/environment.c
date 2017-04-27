#include "headers.h"

env* g_global_environment;

env* setup_environment(char** vars, void** data)
{
    return g_global_environment;
}

env* create_environment(char** vars, void** data, env* outer)
{
    env* new_env = NULL;

    return new_env;
}

void* lookup_variable(char* var, env* current)
{
    void* data = NULL;

    return data;
}


int insert_variable(char* var, void* data, env* current)
{
    return 0;
}
