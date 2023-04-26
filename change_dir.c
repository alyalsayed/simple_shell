#include <errno.h>
#include "main.h"

/**
 * change_dir - change directory
 * @args: arguments
 *
 * Change the current directory to the directory specified in args[1].
 * If there is an error, an error message is printed.
 */
void change_dir(char **args)
{
	if (args[1] == NULL)
	{
		dprintf(STDERR_FILENO, "ash: expected argument to \"cd\"\n");
	}
	else if (chdir(args[1]) != 0)
	{
		perror("ash");
	}

	free(args);
}
