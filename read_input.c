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
/**
 * tokenize2 - function to handle commandline with arguments
 * @cmd: the command with arguments
 * Return: an array of tokens
 */
char **tokenize2(char *cmd)
{
  char **tokens;
  char *tok, *temp;
  int i;
  if (!tokens)
    {
      perror("token error");
      return (NULL);
    }
  cmd = rm_newline(cmd);
  temp = _strdup(cmd);
  tok = strtok(temp, " ");
  for (i = 0; tok; i++)
    {
      token[i] = _strdup(tok);
      tok = strtok(NULL, " ");
    }
  tokens[i] = NULL;
  free(temp);
  return (tokens);
}
