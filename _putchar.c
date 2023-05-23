#include "shell.h"

/**
 * _putchar - writes a only a character
 * @c: char
 * Return: return statement
 * On error, -1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - prints a string
 * @str: string to write
 */
void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
}

/**
 * print - this funnction prints a string
 * @str: the string
 * Return: number of bytes of str
 */
int print(char *str)
{
	int n_bytes = _strlen(str);

	return (write(STDOUT_FILENO, str, n_bytes));
}
