#include "main.h"

/**
 * get_built_in_function - Run built-in commands
 * @command_name: The name of the command
 * Return: the command's function or NULL
*/
void (*get_built_in_function(char *command_name))(char **)
{
	int i = 0;
	/* Array of our built-in commands name and their function */
	built_in_command_t commands[] = {
		{"exit", exit_shell},
		{"env", print_env},
		{NULL, NULL},
	};

	while (commands[i].name)
	{
		if (_strcmp(command_name, commands[i].name) == 0)
			return (commands[i].function);
		i++;
	}
	return (NULL);
}
