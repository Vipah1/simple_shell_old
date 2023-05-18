#include "shell.h"
/**
 * execc_cmd - this unction executes received input as commands
 * @cmd: the command to be execcuted
 * Return: this is a void function
 */
void exec_cmd(char *cmd)
{
  pid_t pid;
  pid = fork();
  if (pid == -1)
    {
      perror("fork");
      exit(EXIT_FAILURE);
    }
  else if (pid == 0)
    {
      /*child process starts here */
      if (execve(cmd, NULL, NULL) == -1)
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
