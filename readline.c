#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * readline - read from stdin
 *
 * Return: string on success
 */
char *readline(void)
{
	size_t length = 0;
	__ssize_t read;
	char *command;

	read = getline(&command, &length, stdin);
	if (read == -1 && feof(stdin))
		exit(EXIT_SUCCESS);
	else if (read == -1)
	{
		perror("Error during line reading.");
		exit(EXIT_FAILURE);
	}

	return (command);
}
