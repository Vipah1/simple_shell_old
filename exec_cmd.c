#include "shell.h"
/**
 * exec_cmd - this unction executes received input as commands
 * @cmd: the command to be execcuted
 * Return: this is a void function
 */
void exec_cmd(char *cmd)
{
  pid_t pid;
  int status;
  pid = fork();
  if (pid == -1)
    {
      perror("fork");
      exit(EXIT_FAILURE);
    }
  if (pid == 0)
    {
      /*child process starts here */
      if (execve(cmd, NULL, environ) == -1)
	{
	  perror("execve");
	  exit(EXIT_FAILURE);
	}
    }
  else
    {
      /* parent proccess waiting to continue */
      wait(NULL);
    }
}  
