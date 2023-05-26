#include "shell.h"
/**
 * _prompt - this is function to prompt user fro input
 * Return: void
 */
void _prompt(void)
{
  /*int p_1, s_1, t_1;
  char *p, *s, *t = "> ";
  char *prompt = NULL;

  p = _getenv("USER");
  s = _getenv("NAME");
  p_1 = _strlen(p);
  s_1 = _strlen(s);
  t_1 = _strlen(t);
  prompt = malloc(p_1 + s_1 + t_1 + 1);
  if (!p || !s || !prompt)
    {
	_puts("$ ");
	return;
    }
  prompt = _strcpy(prompt, p);
  prompt = _strcat(prompt, "@");
  prompt = _strcat(prompt, s);
  prompt = _strcat(prompt, t);
  _puts(prompt);
  free(prompt);*/
  _puts("$ ");
}
