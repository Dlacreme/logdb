#include <stdlib.h>
#include "parser.h"
#include "print.h"

void to_lower(char*);

void setup_input_for_db_create(t_input* input, int ac, char** av) {
    if (ac < MIN_AC_DB_CREATE) {
        return p_error("missing target name to create.");
    }
    t_params_db_create_destroy* params;

    params = malloc(sizeof(t_params_db_create_destroy) * 1);
    params->target = av[3];
    input->command_code = COMMAND_DB_CREATE_CODE;
    input->params = (void*)params;
    input->valid = 1;
}

void setup_input_for_db_destroy(t_input* input, int ac, char** av) {
    if (ac < MIN_AC_DB_DESTROY) {
        return p_error("missing target name to destroy");
    }
    t_params_db_create_destroy* params;

    params = malloc(sizeof(t_params_db_create_destroy) * 1);
    params->target = av[3];
    input->command_code = COMMAND_DB_DESTROY_CODE;
    input->params = (void*)params;
    input->valid = 1;
}

void setup_input_for_db_list(t_input* input, int ac, char** av) {
    if (ac < MIN_AC_DB_LIST) {
        return p_error("missing target name to destroy");
    }
    input->command_code = COMMAND_DB_LIST_CODE;
    input->valid = 1;
}

void setup_input_for_insert(t_input* input, int ac, char** av) {
    if (ac < MIN_AC_INSERT) {
        return p_error("missing target name.");
    }
    input->command_code = COMMAND_INSERT_CODE;
    input->valid = 1;
}

void setup_input_for_fetch(t_input* input, int ac, char** av) {
    if (ac < MIN_AC_FETCH) {
        return p_error("missing target name.");
    }
    input->command_code = COMMAND_FETCH_CODE;
    input->valid = 1;
}

t_input parse_input(int ac, char** argv) {
    t_input input;
    input.target = NULL;
    input.command = NULL;
    input.params = NULL;
    input.valid = 0;
    if (ac < MIN_AC) {
        p_error("invalid input");
        return input;
    }
    input.target = argv[1];
    input.command = argv[2];
    to_lower(input.command);
    if (!strcmp(COMMAND_DB_CREATE, input.command)) {
        setup_input_for_db_create(&input, ac, argv);
    }
    if (!strcmp(COMMAND_DB_DESTROY, input.command)) {
        setup_input_for_db_destroy(&input, ac, argv);
    }
    if (!strcmp(COMMAND_DB_LIST, input.command)) {
        setup_input_for_db_list(&input, ac, argv);
    }
    if (!strcmp(COMMAND_INSERT, input.command)) {
        setup_input_for_insert(&input, ac, argv);
    }
    if (!strcmp(COMMAND_FETCH, input.command)) {
        setup_input_for_fetch(&input, ac, argv);
    }
    return input;
}

void clean_input(t_input input) {
}

void print_input(t_input* input) {
    p_info(input->target);
    p_info(input->command);
}

void to_lower(char* str) {
    while (*str) {
        if (*str >= 'A' && *str <= 'Z') {
            *str += 40;
        }
        str++;
    }
}