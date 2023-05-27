#include "shell.h"
/**
 * split_line - this is the tokenize function
 * @cmd: the input to tokenize
 * Return: tha array of tokens form the split
 */
char **split_line(char *cmd)
{
  int buffer_size = BUFFER_SIZE;
  int i = 0;
  char **tokens = malloc(buffer_size * sizeof(char *));
  char *token;
  if (!tokens)
    {
      perror("Memory allocation error");
      exit(EXIT_FAILURE);
    }
  token = strtok(cmd, TOKEN_DELIMITER);
  while (token != NULL)
    {
      tokens[i] = token;
      i++;
      if (i >= buffer_size)
	{
	  buffer_size += BUFFER_SIZE;
	  tokens = realloc(tokens, buffer_size * sizeof(char *));
	  if (!tokens)
	    {
	      perror("Memory allocation error");
	      exit(EXIT_FAILURE);
	    }
	}
      token = strtok(NULL, TOKEN_DELIMITER);
    }
  tokens[i] = NULL;
  return (tokens);
}
