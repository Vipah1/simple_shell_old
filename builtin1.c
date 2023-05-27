#include "shell.h"
/**
 * cd_cmd - this functions changes directory
 * @args: the array of commands
 * Return: 1 on successs
 */
int cd_cmd(char **args)
{
  if (args[1] == NULL)
    {
      print(stderr);
     _puts( "Expeceted argument to change directory");
      return (-1);
    }
  if (chdir(args[1]) != 0)
    {
      perror("Error changing directory");
      return (-1);
    }
  return (1);
}
/**
 * exit_cmd - this is the exit function
 * @args: the array of command arguments
 * Return: 0 to exit the shell
 */
int exit_cmd(char **args __attribute__((unused)))
{
  return (0);
}
/**
 * env_cmd - this function excute the env command to print env variables
 * @args: the array of command arguments
 * Return: 1 n sucess
 */
int env_cmd(char **args __attribute__((unused)))
{
  extern char **environ;
  char **env = environ;
  while (*env != NULL)
    {
      printf("%s\n", *env);
      env++;
    }
  return 1;
}
