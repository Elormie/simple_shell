#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>

void _print(const char *input);
void print_prompt(void);
void exec_input(const char *input);
void read_input(char *input, size_t size);

#endif /* SHELL_H */
