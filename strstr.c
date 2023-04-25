#include "main.h"
#include <stdio.h>

/**
 * _strstr - Search a sub-string in a string
 * @haystack: The string to search inside
 * @needle: The string to search
 * Return: char-pointer
*/
char *_strstr(char *haystack, char *needle)
{
int i = 0, j = 0;
if (_strlen(needle) == 0)
	return (haystack);
while (haystack[i] != '\0')
{
	if (j == (int)_strlen(needle))
		return (needle);
	else if (haystack[i] == needle[j])
		j++;
	else if (j > 0)
		j = 0;
	i++;
}
return (NULL);
}
