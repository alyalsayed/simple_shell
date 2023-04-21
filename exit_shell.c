#include <stdlib.h>

/**
 * exit - Exit the shell
 * @args: Passed arguments
 * Return: void
*/
void exit_shell(char **args)
{
	free(args);
	exit(EXIT_SUCCESS);
}