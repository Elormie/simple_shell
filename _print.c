#include "shell.h"

/**
 *_print: it prints strings of characters 
*/

void _print(const char *my_str)
{
    write(STDOUT_FILENO, my_str, strlen(my_str));
}
