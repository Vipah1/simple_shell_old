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
/**
 * execute - this function executes a commanf with arguments
 * @args: this is an array of command arguments
 * Return: 1 on success, -1 on error
 */
int execute(char ** args)
{
  pid_t pid;
  int status;
  pid = fork();
  if (pid == 0)
    {
      /* child Process */
      if (execve(args[0], args, environ) == -1)
      {
	perror("Error executing command");
      }
exit(EXIT_FAILURE);
    }
 else if (pid < 0)
   {
     /* Error forking */
     perror("Errorforking");
   }
 else
   {
     /* Parent process */
     do
       {
	 waitpid(pid, &status, WUNTRACED);
       }
     while (!WIFEXITED(status) && !WIFSIGNALED(status));
   }
return 1;
}
/**
 * launch_cmd - this function launches a command
 * @args: the array of command arguments
 * Return: 1 on sucess, -1 on error
 */
int launch_cmd(char ** args)
{
  if (_strcmp(args[0], "cd") == 0)
    {
      return cd_cmd(args);
    }
  else if (_strcmp(args[0], "exit") == 0)
    {
      return exit_cmd(args);
    }
  else if (_strcmp(args[0], "env") == 0)
    {
      return env_cmd(args);
    }
  else if (_strcmp(args[0], "setenv") == 0)
    {
      return setenv_cmd(args);
    }
  else if (_strcmp(args[0], "unsetenv") == 0)
    {
      return unsetenv_cmd(args);
    }
  else if (_strcmp(args[0], "alias") == 0)
    {
      return alias_cmd(args);
    }
  return execute(args);
}
