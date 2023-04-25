#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * print_env - List env variables
 * Return: void
*/
void print_env(char **args)
{
int i = 0;
while (environ[i])
{
	printf("%s\n", environ[i]);
	i++;
}
free(args);
}
