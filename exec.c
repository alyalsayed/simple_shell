#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * exec - Execute a command
 * @commands: Commands array
 * @env: The environment variable
 * Return: void
 */
void exec(char **commands, char **env)
{
	__pid_t pid;
	if (get_built_in_function(commands[0]))
		get_built_in_function(commands[0])(commands);
	else
	{
		pid = fork();
		if (pid == -1)
		{
			perror("Error during process creation");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0 && execve(commands[0], commands, env) == -1)
		{
			perror("Error during command execution");
			exit(EXIT_FAILURE);
		}
	}
}
