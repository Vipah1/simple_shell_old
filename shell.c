#include "shell.h"
/**
 * main - the entry point of the shell program
 * Return: 0 on sucess
 */
int main(void)
{
	char *cmd;
	size_t bufsize = 0;

	while (1)
	{
		_prompt();
		cmd = read_input(&bufsize);
		if (cmd == NULL)
		{
			break;
		}
		exec_cmd(cmd);
	}
	return (0);
}
