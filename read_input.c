#include "shell.h"
/**
 * read_input - Function that reads input from the user
 * @bufsize: the size or length of the input
 * Return: Returns input from the user
 */
char *read_input(size_t *bufsize)
{
	char *input = NULL;
	ssize_t nread;

	nread = getline(&input, bufsize, stdin);
	if (nread == -1)
	{
		/*handle end-of-file*/
		if (feof(stdin))
		{
			free(input);
			_putchar('\n');
			return (NULL);
		}
		else
		{
			perror("getline error");
			exit(EXIT_FAILURE);
		}
	}
	/* removes trailing new line character */
	if (input[nread - 1] == '\n')
		input[nread - 1] = '\0';
	return (input);
}
