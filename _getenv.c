#include "shell.h"
/**
 * _getenv - this functions gets the value of the environmental variables
 * @name: this is the name of the variable
 * Return: returns the value of @name parameter
 */
char *_getenv(const char *name)
{
  int i = 0;
  int j = 0;
  while (environ[i])
    {
      while (environ[i][j] && *name)
	{
	  if (environ[i][j] != *name || (environ[i][j] == '='))
	    {
	      break;
	    }
	  j++, name++;
	}
      if (environ[i][j] == '=' && !*name)
	{
	  return ((*(envron + i) + ++j));
	}
      i++;
    }
  return (NULL);
}
