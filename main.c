#include "shell.h"
/**
 * main - the entry point
 * @argc: the number of command-line arguments
 * @agv: the array of comman-line arguments
 */
int main(int argc, char **argv)
{
  char *cmd;
  char **cmds;
  int num_cmd;
  if (argc > 1)
    {
      // execute commads frooma file
      FILE *file = fopen(argv[1], "r");
      if (file == NULL)
	{
	  perror("Error opening file");
	  return (EXIT_FAILURE);
	}
      while ((cmd = _getline(file)) != NULL)
	{
	  cmds = split_line(cmd);
	  num_cmd = 0;
	  while (cmds[num_cmd] != NULL)
	    {
	      num_cmd++;
	    }
	  handle_logical_operators(cmds, num_cmd);
	  free(cmd);
	  free(cmds);
	}
      fclose(file);
      return (EXIT_SUCCESS);
    }
  // INTERACTIVE MODE
  do {
    printf("$ ");
    cmd = _getline();
    cmds = split_line(cmd);
    num_cmd = 0;
    while (cmds[num_cmd] != NULL){
      num_cmd++;
    }
    handle_logical_operators(cmds, num_cmd);
    free(cmd);
    free(cmds);
  } while (1);
  return (EXIT_SUCCESS);
}
