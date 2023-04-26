#include <stdio.h>
#include "main.h"

/**
 * launch_shell - launch the shell
 * Return: void
 */
void launch_shell(void)
{
	char *command;
	char **args;

	while (1)
	{
		printf("$ ");
		command = readline();
		args = split(command);
		if (args[0] == NULL)
			continue;
		exec(args);
	}
}
