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
#include <errno.h>

#define BUFSIZE 1024
#define TRUE 1
#define FALSE 0

extern char **environ;

void _prompt(void);
char *read_input(size_t *bufsize);
int exec_cmd(char **cmd, char *filename);
char *build_path(char *cmd, char *value);
char **tokenize(char *s, const char *delimiter);

/* printing tools */
int _putchar(char c);
void _puts(char *str);
int print(char *str);
/* string manipulating tools */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _strlen(char *s);
char *_strdup(char *str);
char *_strstr(char *haystack, char *needle);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
int _strcmp(char *s1, char *s2);

char *_getenv(const char *name);

/**
 * struct builtin_t - this structure is for builtin commands
 * @cmd: this is the command name
 * @f: this is the correct function to be called
 */
typedef struct builtin_t
{
	char *cmd;
	int (*f)(char **, int, char *);
} builtin_t;

/* utils */
void free_memory_p(char *);
void free_memory_pp(char **);
int cmp(const char *s1, const char *s2);
int _atoi(char *s);
int _isalpha(char c);

int check_cmd_path(char **cmd);
char *rm_newline(char *cmd);
/* builtins */
int exit_cmd(char **, int, char *);
int env_cmd(char **, int, char *);
builtin_t is_builtin(char *cmd);
int (*check_builtins(char **))(char **, int, char *);
#endif
