#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * checkalloc - Check if an allocation work
 * @ptr: Pointer to check
 * Return: void or exit with error if allocation failed
*/
void checkalloc(void *ptr)
{
	if (ptr == NULL)
	{
		dprintf(STDERR_FILENO, "ash: Error during memory allocation.");
		exit(1);
	}
}
