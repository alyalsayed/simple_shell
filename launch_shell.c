#include <stdio.h>
#include "main.h"

/**
 * launch_shell - Launch the shell
 * @env: Environment variable
 * Return: 1 if success or 0 if failed
*/
void launch_shell(char **env)
{
char *command;
(void)env;
while (1)
{
	printf("$ ");
	command = readline();
	printf("%s\n", command);
}
}
