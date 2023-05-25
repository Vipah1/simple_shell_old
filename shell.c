#include "shell.h"
/**
 * main - the entry point of the shell program
 * @argc: Unused
 * @argv: this is an array of comman line arguments parsed to the command name
 * Return: 0 on sucess
 */
int main(int argc __attribute__((unused)), char *argv[])
{
	int (*builtin)(char **, int, char *);
	char **tokens;
	char *cmd;
	size_t len = 0;
	ssize_t nread;
	int status = 0;

	while (1)
	{
	  if (isatty(STDIN_FILENO))
	    {
		_prompt();
	    }
		nread = getline(&cmd, &len, stdin);
		if (nread == -1)
			return (-1);
		if (*cmd == '\n' || *cmd == '\0')
			continue;
		cmd = rm_newline(cmd);
		tokens = tokenize(cmd, " ");
		/* second argument is the delimiter that splits the string */
		if (!tokens || !tokens[0])
			continue;
		builtin = check_builtins(tokens);
		if (builtin)
		{
			status = builtin(tokens, status, argv[0]);
			free_memory_pp(tokens);
			continue;
		}
		else
		{
			status = exec_cmd(tokens, argv[0]);
		}
		free_memory_pp(tokens);
	}
	return (0);
}

/**
 * check_cmd_path - this function checks if the command exists in the path
 * @cmd: the command
 * Return: 0 if exists
 */
int check_cmd_path(char **cmd)
{
	char *path, *value, *cmd_path;
	struct stat buf;

	path = _getenv("PATH");
	value = strtok(path, ":");
	while (value)
	{
		cmd_path = build_path(*cmd, value);
		if (stat(cmd_path, &buf) == 0)
		{
			*cmd = _strdup(cmd_path);
			free(cmd_path);
			return (0);
		}
		free(cmd_path);
		value = strtok(NULL, ":");
	}
	return (1);
}

/**
 * rm_newline - this functions removes the trailing newline character
 * @cmd: the input from the user
 * Return: returns the altered input received
 */
char *rm_newline(char *cmd)
{
  size_t len = _strlen(cmd);
  if (len > 0 && cmd[len -1] == '\n')
    {
      cmd[len - 1] = '\0';
    }
  char *tmp = _strdup(cmd);
	return (tmp);
}
