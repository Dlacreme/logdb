#include "print.h"

#define RESET "\033[0m"
#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"
#define GREEN "\033[0;32m"

void p_error(const char* error)
{
    p_color(RED, error);
}

void p_warning(const char* warning)
{
    p_color(YELLOW, warning);
}

void p_info(const char* warning)
{
    p_color(RESET, warning);
}

void p_success(const char* warning)
{
    p_color(GREEN, warning);
}

void p_color(const char* color, const char* message)
{
    printf(color);
    printf(message);
    printf(RESET);
    printf("\n");
}
