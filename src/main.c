#include "print.h"
#include "parser.h"

void run(t_input);

int main(int ac, char** argv)
{
    t_input input;

    input = parse_input(ac, argv);
    if (input.valid == 0) {
        p_error("invalid input.");
        return -1;
    }
    run(input);
    clean_input(input);
    return 0;
}
