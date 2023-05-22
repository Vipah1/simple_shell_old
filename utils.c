#include "shell.h"
/**
 * free_memory-p - this function frees a pointer
 * @ptr: the pointer to be freeed
 */
void free_memory_p(char *ptr)
{
  if (ptr != NULL)
    {
      free(ptr);
      ptr = NULL;
    }
  ptr = NULL;
}
/**
 * free_memory_pp - this function frees a double pointer
 *@ptr: the double pointer to be freed
 */
voidfree_memory_pp(char **ptr)
{
  char **tmp;
  for (tmp = ptr; *tmp != NULL; tmp++)
    free_memory_p(*tmp);
  free(ptr);
}
/**
 * cmp - this function checks for a string in another
 * @s1: the string to be searched
 * @s2: this is the string being searched for
 * Description: this is the diffeerent from the _strcmp function
 * Return: 1 if found or 0
 */
int cmp(const char *s1, const char *s2)
{
  while (*s1 && *s2)
    if (*s1++ != *s2++)
      return (0);
  return (*s2 == '\0');
}
/** 
 * isalpha - this function checks if a character is a letter
 * @c: the given character
 * Return: returns true if true or false
 */
int _isalpha(char c)
{
  if ((c >= 48) && (c <= 57))
    return(FALSE);
  return (TRUE);
}
/** _atio - this function converts a string to an integer
 * @s: the string to be converted

 * Return: returns int
 */
int _atoi(char *s)
{
  int len, i = 0, FLAG = 0, d = 0, n = 0, digit;
  for (len = 0; s[len] != '\0'; len++)
    ;
  while (i < len && FLAG == 0)
    {
      if (s[i] == '-')
	++d;
      if (s[i] >= 48 && s[i] <= 57)
	{
	  digit = s[i] - '0';
	  if (d % 2)
	    digit = -digit;
	  n = n * 10 + digit;
	  FLAG = 1;
	  if (s[i + 1] < 48 || s[i + 1] > 57)
	    break;
	  FLAG = 0;
	}
      i++;
    }
  if (FLAG == 0)
    return (0);
  return (n);
}
