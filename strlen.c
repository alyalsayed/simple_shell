#include <stddef.h>

/**
 * _strlen - Get the lenght of a string
 * @s: The string
 * Return: the size of the string
*/
size_t _strlen(char *s)
{
	int i = 0;
	while (s[i] != '\0')
		i++;
	return ((size_t)i);
}
