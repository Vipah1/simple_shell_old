#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define BUFSIZE 1024

void _prompt(void);
char read_input(size_t *bufsize);
void exec_cmd(char *cmd);
int _putchar(char c);


#endif
