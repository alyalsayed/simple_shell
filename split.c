#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "main.h"

/**
 * split - explode a string into different parts
 * @str: string to explode
 *
 * Return: pointer to char-pointer
 */
char **split(char *str)
{
	int index = 0;
	int parts_size = 64;
	const char *separators = " \t\n\r\a";
	char *part;
	char **parts = malloc(sizeof(char *) * parts_size);

	checkalloc(parts);
	part = strtok(str, separators);

	while (part != NULL)
	{
		if (index >= parts_size)
		{
			parts_size += 64;
			parts = realloc(parts, sizeof(char *) * parts_size);
			checkalloc(parts);
		}
		parts[index] = part;
		index++;
		part = strtok(NULL, separators);
	}

	parts[index] = NULL;

	return (parts);
}
