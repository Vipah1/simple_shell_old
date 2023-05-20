#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <limits.h>
#include <signal.h>

#define BUFSIZE 1024

extern char **environ;

void _prompt(void);
char *read_input(size_t *bufsize);
void exec_cmd(char *cmd);
int _putchar(char c);
void _puts(char *str);

#endif
