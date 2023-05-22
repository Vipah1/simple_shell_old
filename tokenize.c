#include "shell.h"

/**
 * _realloc - reallocate a memo block with malloc+free
 * @ptr: pointer to the previous allocated memory
 * @old_size: old size
 * @new_size: new size
 * Return: NULL or new dest
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i;
	char *dest;
	char *src;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		ptr = malloc(new_size);
		return (ptr);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	dest = malloc(new_size);
	src = ptr;
	if (dest == NULL)
		return (NULL);

	if (new_size > old_size)
	{
		for (i = 0; i < old_size; i++)
			dest[i] = src[i];
		free(ptr);
		for (i = old_size; i < new_size; i++)
			dest[i] = src[i];
	}
	if (new_size < old_size)
	{
		for (i = 0; i < new_size; i++)
			dest[i] = src[i];
		free(ptr);
	}
	return (dest);
}

/**
 * _strdup - duplicates a string
 * @str: string
 * Return: result string
 */
char *_strdup(char *str)
{
	char *result;
	int i = 0;

	if (str == NULL)
		return (NULL);

	result = malloc(_strlen(str) + 1);
	if (result == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	while (str[i] != '\0')
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';

	return (result);
}

/**
 * _strlen - returns the length of a string
 * @s: string
 * Return: the length
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
	}
	return (i);
}

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

/**
 * build_path - this functions builds thepath from a command
 * @token: this is the given command
 * @value: this is the path to build
 * Return: the path for @token/@value
 */
char *build_path(cahr *token, char *value)
{
  char *cmd;
  size_t len;
  len = _strlen(value) + _strlen(token) + 2);
cmd = malloc(sizeof(char) * len);
if (!cmd)
  return (NULL);
memset(cmd, 0, len);
cmd = _strcat(cmd, value);
cmd = _strcat(cmd, "/");
cmd = _strcat(cmd, token);
return (cmd);
}
