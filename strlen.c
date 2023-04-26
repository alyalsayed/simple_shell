#include <stddef.h>

/**
 * _strlen - get the length of a string
 * @s: the string
 *
 * Return: the size of the string
 */
size_t _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;

	return (size_t)i;
}
