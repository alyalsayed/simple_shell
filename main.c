#include <stdlib.h>
#include "main.h"

/**
 * main - program entry point
 * @argc: arguments count
 * @argv: arguments array
 *
 * Return: 0 on success or 1 if error encountered
 */
int main(int argc, char **argv)
{
	int ac = (argc - 1);
	int i = 0;
	char **av;

	if (argc > 1)
	{
		av = malloc(sizeof(char *) * ac);
		checkalloc(av);
		while (i < argc)
		{
			av[i] = argv[i + 1];
			i++;
		}
		av[i] = NULL;
		exec(av);
	}
	else
		launch_shell();

	return (0);
}
