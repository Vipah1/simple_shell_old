#include "shell.h"

/**
 * _realloc - 
 */

/**
 * _strdup - 
 */

/**
 * _strlen - 
 */

/**
 * tokenize - splits a string
 * @s: string
 * @delimiter: delimiter string
 * Return: double pointer
 */
char **tokenize(char *s, const char *delimiter)
{
	char **arr;
	int i = 0, j;
	char *token, *tmp;

	tmp = malloc(_strlen(s) + 1);
	if (tmp == NULL)
	{
		/*perror(_getenv("_"));*/
		return (NULL);
	}

	while (s[i])
	{
		tmp[i] = s[i];
		i++;
	}
	tmp[i] = '\0';

	token = strtok(tmp, delimiter);
	arr = malloc(sizeof(char *) * 2);
	arr[0] = _strdup(token);

	i = 1;
	j = 3;
	while (token)
	{
		token = strtok(NULL, delimiter);
		arr = _realloc(arr, (sizeof(char *) * (j - 1)), (sizeof(char *) * j));
		arr[i] = _strdup(token);
		i++;
		j++;
	}
	free(tmp);
	return (arr);
}
