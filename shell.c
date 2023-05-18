#include "shell.h"
/**
 * main - the entry point of the shell program
 *
 * Return: 0 on sucess
 */
int main(void)
{
  char buf[BUFSIZE];
  while (1)
    {
      _prompt();
      if (read_input(buf, BUFSIZE) == -1)
	{
	  exit(EXIT_FAILURE);
	}
      exec_cmd(buf);
    }
  return (0);
}
