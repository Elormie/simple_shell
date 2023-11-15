#include "shell.h"

/**
 * 
*/

void read_input(char *input, size_t size)
{
    if (fgets(input, size, stdin) == NULL)
    {
        if (feof(stdin))
        {
            _print("\n");
            exit(EXIT_SUCCESS);
        }

        else
        {
            _print("Error\n");
            exit(EXIT_FAILURE);
        }
    }
    input[strcspn(input, "\n")] = '\0';
}
