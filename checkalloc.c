#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * checkalloc - check if an allocation worked
 * @ptr: pointer to check
 *
 * Return: void or exit with error if allocation failed
 */
void checkalloc(void *ptr)
{
	if (ptr == NULL)
	{
		dprintf(STDERR_FILENO, "ash: Error during memory allocation.\n");
		exit(1);
	}
}
