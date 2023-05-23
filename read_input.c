#include "shell.h"
/**
 * read_input - Function that reads input from the user
 * @bufsize: the size or length of the input
 * Return: Returns input from the user
 */
char *read_input(size_t *bufsize __attribute__((unused)))
{
	char *input = NULL;
	ssize_t nread;
	size_t len = 0;

	nread = getline(&input, &len, stdin);
	if (nread == -1)
	{
		/*handle end-of-file*/
		/**
		*if (feof(stdin))
		*{
		*	free(input);
		*	_putchar('\n');
		*	return (NULL);
		*}
		*else
		*{
		*	perror("getline error");
		*	exit(EXIT_FAILURE);
		*}
		*/
		return (NULL);
	}
	if (*input == '\n' || *input == '\0')
	{
		/*continue;*/
	}
	/* removes trailing new line character */
	if (input[nread - 1] == '\n')
		input[nread - 1] = '\0';
	return (input);
}
