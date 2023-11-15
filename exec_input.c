#include "shell.h"


/**
 * 
*/

void exec_input(const char *input)
{
    /*creating a child process*/
    pid_t c_pid = fork(); 

    if (c_pid == -1)
    {
        _print("Forking Unsuccessful.\n");
        exit(EXIT_FAILURE);
    }

    else if (c_pid == 0)
    {
        char *args[100]; 
        int arg_count = 0;

        char *token = strtok((char *)input, " ");
        while (token != NULL) 
        {
            args[arg_count++] = token;
            token = strtok(NULL, " ");
        }
        args[arg_count] = NULL;

        execvp(args[0], args);

        _print("Error executing input.\n");
        exit(EXIT_FAILURE);
    }

    else 
    {
        wait(NULL);
    }
}
