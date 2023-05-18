#include "shell.h"
/**
 * read_input - Function that reads input from the user
 * @buf: the input to read
 * @bufsize: the size or length of the input
 * Return: Returns input from the user
 */
int read_input(char *buf, size_t bufsize)
{
  ssize_t nread;
  nread = getline(&buf, &bufsize, stdin);
  if(nread == -1)
    {
      /*handle end-of-file*/
      if(feof(stdin))
	{
	  _putchar('\n');
	  return (-1);
	}
      else
	{
	  perror("getline error");
	  return (-1);
	}
    }
  /* removes trailing new line characters */
  buf[strcspn(buf, "\n")] = '\0';
  return (0);
}
