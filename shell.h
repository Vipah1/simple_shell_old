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
char **tokenize(char *s, const char *delimiter);
/* printing tools */
int _putchar(char c);
void _puts(char *str);
/* string manipulating tools */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _strlen(char *s);
char *_strdup(char *str);

#endif
