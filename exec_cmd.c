#include "shell.h"
/**
 * exec_cmd - this unction executes received input as commands
 * @cmd: the command to be execcuted
 * @filename: the name of the shell program
 * Return: this is a void function
 */
int exec_cmd(char **cmd, char *filename __attribute__((unused)))
{
	pid_t pid;
	int status;

	if (!*cmd)
		exit(-1);
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(-1);
	}
	if (pid == 0)
	{
		if (strncmp(cmd[0], "./", 2) && strncmp(cmd[0], "./", 1))
		{
			check_cmd_path(cmd);
		}
		/*child process starts here */
		if (execve(cmd[0], cmd, environ) == -1)
		{
			perror("filename");
			free_memory_pp(cmd);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* parent proccess waiting to continue */
		wait(&status);
		if (WIFEXITED(status))
		{
			return (WEXITSTATUS(status));
		}
	}
	return (0);
}
