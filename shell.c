#include "shell.h"
/**
 * 
 * 
*/

void _print(const char *my_str);
void exec_input(const char *input);
void print_prompt(void);
void read_input(char *input, size_t size);

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

/**
 * 
*/

void print_prompt(void)
{
    _print(":)$");
}


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

/**
 * 
*/

void _print(const char *my_str)
{
    write(STDOUT_FILENO, my_str, strlen(my_str));
}
