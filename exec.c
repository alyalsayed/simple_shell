#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * exec - Execute a command
 * @commands: Commands array
 * Return: void
 */
void exec(char **commands)
{
	__pid_t pid;
	int status;
	if (get_built_in_function(commands[0]))
		get_built_in_function(commands[0])(commands);
	else
	{
		pid = fork();
		if (pid < 0)
		{
			perror("Error during process creation");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (execvp(commands[0], commands) == -1)
				perror("Error during command execution");
			exit(EXIT_FAILURE);
		}
		else
			waitpid(pid, &status, WUNTRACED);
	}
}
