#include "shell.h"
/**
 * handle_logical_operators - Handle logical operators (&& and ||) in commands.
 * @commands: The array of commands to execute.
 * @num_commands: The number of commands in the array.
 */
void handle_logical_operators(char **commands, int num_commands)
{
    int i, status;

    for (i = 0; i < num_commands; i++) {
        char **args = split_line(commands[i]);

        if (args[0] != NULL) {
            if (strcmp(args[0], "&&") == 0) {
                if (status == 0) {
                    status = launch_command(args + 1);
                }
            } else if (strcmp(args[0], "||") == 0) {
                if (status != 0) {
                    status = launch_command(args + 1);
                }
            } else {
                status = launch_command(args);
            }
        }

        free(args);
    }
}

/**
 * replace_variable - Replace a variable with its value in a string.
 * @line: The input string.
 * @variable: The variable to replace.
 * @value: The value to replace the variable with.
 *
 * Return: The modified string with the variable replaced.
 */
char *replace_variable(char *line, char *variable, char *value)
{
    char *result = malloc(BUFFER_SIZE * sizeof(char));
    char *ptr = line;
    char *variable_ptr;
    char *dollar_ptr;
    int variable_length = strlen(variable);
    int value_length = strlen(value);
    int result_length = 0;

    if (!result) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    while ((dollar_ptr = strchr(ptr, '$')) != NULL) {
        // Copy the text before the $
        strncpy(result + result_length, ptr, dollar_ptr - ptr);
        result_length += dollar_ptr - ptr;

        // Check if the $ is followed by the variable
        if (strncmp(dollar_ptr + 1, variable, variable_length) == 0) {
            variable_ptr = dollar_ptr + 1;
            strncpy(result + result_length, value, value_length);
            result_length += value_length;
            variable_ptr += variable_length;
            ptr = variable_ptr;
        } else {
            // Copy the $ and continue
            strncpy(result + result_length, dollar_ptr, 1);
            result_length++;
            ptr = dollar_ptr + 1;
        }
    }

    // Copy the remaining text
    strncpy(result + result_length, ptr, strlen(ptr));
    result_length += strlen(ptr);

    // Null-terminate the result
    result[result_length] = '\0';

    return result;
}

/**
 * replace_variable_in_args - Replace environment variables in command arguments.
 * @args: The array of command arguments.
 */
void replace_variable_in_args(char **args)
{
    char **ptr = args;
    char *variable;
    char *value;

    while (*ptr != NULL) {
        if ((variable = strchr(*ptr, '$')) != NULL) {
            variable++;
            if ((value = getenv(variable)) != NULL) {
                *ptr = replace_variable(*ptr, variable, value);
            }
        }
        ptr++;
    }
}
