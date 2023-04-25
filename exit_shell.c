#include <stdlib.h>
#include "main.h"

/**
 * exit_shell - Exit the shell
 * @args: Passed arguments
 * Return: void
*/
void exit_shell(char **args)
{
	if (args[1])
		exit(_atoi(args[1]));
	exit(EXIT_SUCCESS);
	free(args);
}
