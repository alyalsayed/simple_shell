/**
 * _strcmp - Compare two string
 * @__s1: First string
 * @__s2: Second string
 * Return: 0 if there is a match or 1 if not
*/
int _strcmp(char *__s1, char *__s2)
{
int i = 0;
while (__s1[i] != '\0' && __s2[i] != '\0')
{
	if (__s1[i] != __s2[i])
		return (1);
	i++;
}
if (__s1[i] == '\0' && __s2[i] == '\0')
	return (0);
else
	return (1);
}
