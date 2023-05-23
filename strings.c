#include "shell.h"

/**
 * _strstr - this function implements the strstr function
 * @haystaack: needle in a haystack
 * @needle: the needle (string to be searched)
 * Return: returns a pointer to the first character of the needle
 */
char *_strstr(char *haystack, char *needle)
{
	while (*haystack)
	{
		if ((*haystack == *needle) && cmp(haystack, needle))
		{
			return (haystack);
		}
		haystack++;
	}
	return (NULL);
}

/**
 * _strcpy - this function copies the content of a string to another
 * @dest: the destination of the the string
 * @src: the sourcce of the copied string
 * Return: the destination
 */
char *_strcpy(char *dest, const char *src)
{
	char *temp = dest;
	
	while (*src)
		*temp++ = *src++;
	*temp = '\0';
	return (dest);
}

/**
 * _strcat - this function concantenates two strings
 * @dest: the destination of the string
 * @src: the sources of the string
 * Return: the resultant of the concantenation
 */
char *_strcat(char *dest, const char *src)
{
	int len_dest, i = 0;
	
	len_dest = _strlen(dest);
	while (src[i])
		dest[len_dest++] = src[i++];
	dest[len_dest] = '\0';
	return (dest);
}

/**
 * _strcmp - this function compares two strings
 * @s1: first string to be compared
 * @s2: the second string 
 * Return: 0 if equal
 */
int _strcmp(char *s1, char *s2)
{
	int i;
	
	for (i = 0; s1[i]; i++)
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	return (0);
}
