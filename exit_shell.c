#include <stdlib.h>
#include "main.h"

/**
 * exit_shell - exit the shell
 * @args: arguments passed to the function
 *
 * Return: void
 */
void exit_shell(char **args)
{
	if (args[1])
		exit(_atoi(args[1]));

	exit(EXIT_SUCCESS);
}
