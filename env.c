#include "shell.h"
/**
 * setenv_cmd - Execute the "setenv" command to set an environment variable.
 * @args: The array of command arguments.
 *
 * Return: 1 on success, -1 on error.
 */
int setenv_cmd(char **args)
{
    if (args[1] == NULL || args[2] == NULL) {
        fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
        return -1;
    }

    if (setenv(args[1], args[2], 1) != 0) {
        perror("Error setting environment variable");
        return -1;
    }

    return 1;
}

/**
 * unsetenv_cmd - Execute the "unsetenv" command to unset an environment variable.
 * @args: The array of command arguments.
 *
 * Return: 1 on success, -1 on error.
 */
int unsetenv_cmd(char **args)
{
    if (args[1] == NULL) {
        fprintf(stderr, "Usage: unsetenv VARIABLE\n");
        return -1;
    }

    if (unsetenv(args[1]) != 0) {
        perror("Error unsetting environment variable");
        return -1;
    }

    return 1;
}

/**
 * alias_cmd - Execute the "alias" command to set an alias.
 * @args: The array of command arguments.
 *
 * Return: 1 on success, -1 on error.
 */
int alias_cmd(char **args)
{
    if (args[1] == NULL || args[2] == NULL) {
        fprintf(stderr, "Error: expected arguments to \"alias\"\n");
    } else {
        setenv(args[1], args[2], 1);
    }
    return 1;
}
