#include "command.h"
#include "parser.h"
#include "print.h"

int run(t_input input) {
    if (input.command_code == COMMAND_DB_CREATE_CODE) {
        return db_create();
    }
    if (input.command_code == COMMAND_DB_DESTROY_CODE) {
        return db_destroy();
    }
    if (input.command_code == COMMAND_DB_LIST_CODE) {
        return db_list();
    }
    p_error("unknown command.");
    return -1;
}