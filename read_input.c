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
	if (!input)
	  {
	    perror("Memory allocation error");
	    exit(EXIT_FAILURE);
	  }
	if (nread == -1)
	{
		/*handle end-of-file*/
	  free(input);
	  return (NULL);
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
  if (!cmd)
    return (NULL);
  tokens = malloc(sizeof(char *) * _strlen(cmd));
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
      tokens[i] = _strdup(tok);
      tok = strtok(NULL, " ");
    }
  tokens[i] = NULL;
  free(temp);
  return (tokens);
}
