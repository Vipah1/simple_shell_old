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
#define BUFFER_SIZE 1024
#define TOKEN_DELIMITER " \t\r\n\a"


extern char **environ;

void _prompt(void);
char *read_input(size_t *bufsize);
int exec_cmd(char **cmd, char *filename __attribute__((unused)));
char *build_path(char *token, char *value);
char **tokenize(char *s, const char *delimiter);
char **tokenize2(char *cmd);
char **split_line(char *cmd)
/* in env.c */
int env_cmd(char **args);
int setenv_cmd(char **args);
int unsetenv_cmd(char **args);
int alias_cmd(char **args);
/* executing functions */
int launch_cmd(char **args);
int execute(char **args);
/* printing tools */
int _putchar(char c);
void _puts(char *str);
int print(char *str);
char *_getline(void);
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
/*int exit_cmd(char **cmd, int status, char *filename)*/
/*int env_cmd(char **cmd, int status, char *filename);*/
int exit_cmd(char **args);
int env_cmd(char **args);
int cd_cmd(char **args);
builtin_t is_builtin(char *cmd);
int (*check_builtins(char **))(char **, int, char *);

/* in advanced.c */
void replace_variable_in_args(char **args);
char *replace_variable(char *line, char *variable, char *value);
void handle_logical_operators(char **commands, int num_commands);
#endif
