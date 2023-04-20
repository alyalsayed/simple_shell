#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

/**
 * exec - Execute a command
 * @command: Command to execute
 * @env: The environment variable
 * Return: void
*/
void exec(char **commands, char **env)
{
	__pid_t pid;
	pid = fork();
	if (pid == -1)
	{
		perror("Error during process creation");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(commands[0], commands, env) == -1)
		{
			perror("Error during command execution");
			exit(EXIT_FAILURE);
		}	
	}
	else
	{
		int status;
        wait(&status);
	}
}
