#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Program entry point
 * @argc: Arguments count
 * @argv: Arguments array
 * @envp: Environment variable
 * Return: 0 on success or 1 if error encountered
 */
int main(int argc, char **argv, char **envp)
{
	int ac = (argc - 1), i = 0;
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
		exec(av, envp);
	}
	else
		launch_shell(envp);

	return (0);
}
