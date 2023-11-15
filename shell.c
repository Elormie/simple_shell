#include "shell.h"

/**
 * 
 * 
*/

int main(void)
{
    char input[100];

    while(1)
    {
        print_prompt();
        read_input(input, sizeof(input));
        exec_input(input);
    }

    return(0);
}
