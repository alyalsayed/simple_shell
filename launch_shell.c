#include <stdio.h>
#include "main.h"

/**
 * launch_shell - Launch the shell
 * Return: 1 if success or 0 if failed
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
