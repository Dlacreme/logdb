#ifndef parser_h
#define parser_h

#include <string.h>

#define MIN_AC 3
#define MIN_AC_DB_CREATE 4
#define MIN_AC_DB_DESTROY 4
#define MIN_AC_DB_LIST 3
#define MIN_AC_INSERT 5
#define MIN_AC_FETCH 4

#define COMMAND_DB_CREATE "db_create"
#define COMMAND_DB_DESTROY "db_destroy"
#define COMMAND_DB_LIST "db_list"
#define COMMAND_INSERT "insert"
#define COMMAND_FETCH "fetch"

#define COMMAND_DB_CREATE_CODE 1
#define COMMAND_DB_DESTROY_CODE 2
#define COMMAND_DB_LIST_CODE 3
#define COMMAND_INSERT_CODE 4
#define COMMAND_FETCH_CODE 5

typedef struct struct_db_params_create_destroy {
    char* target;
} t_params_db_create_destroy;

typedef struct struct_params_insert {
    char* json;
} t_params_insert;

typedef struct struct_params_fetch {
    char* random;
} t_params_fetch;

typedef struct struct_input {
    char valid;
    char* target;
    char* command;
    char command_code;
    void* params;
} t_input;

t_input parse_input(int, char**);
void print_input(t_input*);
void clean_input(t_input);

#endif
