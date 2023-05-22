#include "shell.h"
/**
 * is_builtin -this function schecks if the command is a uiltin command
 * @cmd: this is the command received
 * Return: returns the position of the command in the builtin   array else return -1
 */
builtin_t is_builtin(char *cmd)
{
  builtin_t builtins[] = {
			  {"exit", exit_cmd},
			  {"env", env_cmd},
			  {NULL, NULL}
  };
  int i;
  for (i = 0; builtins[i].cmd; i++)
    if (_strcmp(builtins[i].cmd, cmd) == 0)
      return (builtins[i]);
  return (builtins[i]);
}
/**
 * check_builtins - his function runs f the command is a builtin command
 * @cmd: this is the argv of the command arguments
 * Return: returns te correct function to be executed else NULL
 */
int (*check_builtins(char **cmd))(char **, int, char *)
{
  builtin_t b = is_builtin(cmd[0]);
  if (b.cmd)
    return (b.f);
  return (NULL);
}
/**
 * env_cmd - this function is a builtin implementation of the env command
 * @cmd: Unused
 * @status: this is the status of the program
 * Return: 0
 */
int env_cmd(char **cmd, int status, char *filename)
{
  int i;
  (void) cmd;
  (void) status;
  (void) filename;
  for (i = 0; environ[i]; i++)
    {
      print(environ[i]);
      _puts('\n');
    }
  return (0);
}
/**
 * exit_cmd - this is a builtin implementation of the exit command
 * @cmd: anthis is an array of the given command 
 * @status: this is the status of the program
 * Return: this exits the program with given status ccode
 */
int exit_cmd(char **cmd, int status, char *filename)
{
  int i = 0;
  if (!cmd[1])
    {
      free_memory_pp(cmd);
      exit(status);
    }
  while (cmd[1][i])
    {
      if _isalpha(cmd[1][i] && cmd[1][i] != '-')
		   {
		     print(filename);
		     print(": ");
		     print("Illegal number: ");
		     print(cmd[1]);
		     _putchar('\n');
		     return (1);
		   }
      i++;
    }
  status = _atoi(cmd[1]);
  free_memory_pp(cmd);
  exit(status);
}
