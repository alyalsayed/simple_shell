#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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
char bin[64] = "/bin/";
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
		if (strstr(commands[0], bin) == NULL)
			commands[0] = strcat(bin, commands[0]);
		if (execve(commands[0], commands, environ) == -1)
			perror(commands[0]);
		free(commands);
		exit(EXIT_FAILURE);
	}
	else
		waitpid(pid, &status, WUNTRACED);
}
}
