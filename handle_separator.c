#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * change_directory - change current working directory
 * @path: path to change to
 */
void change_directory(char *path)
{
    char *old_pwd = getcwd(NULL, 0);

    if (path == NULL)
    {
        path = getenv("HOME");
    }
    else if (strcmp(path, "-") == 0)
    {
        path = getenv("OLDPWD");
        printf("%s\n", path);
    }

    if (chdir(path) == -1)
    {
        perror("cd");
        return;
    }

    setenv("OLDPWD", old_pwd, 1);
    free(old_pwd);

    char *new_pwd = getcwd(NULL, 0);
    setenv("PWD", new_pwd, 1);
    free(new_pwd);
}

/**
 * execute_command - execute a single command
 * @command: command to execute
 */
void execute_command(char *command)
{
    if (strcmp(command, "cd") == 0)
    {
        change_directory(strtok(NULL, " \t\n"));
    }
    else if (strcmp(command, "exit") == 0)
    {
        exit(EXIT_SUCCESS);
    }
    else
    {
        pid_t pid = fork();
        if (pid == -1)
        {
            perror("fork");
            return;
        }
        else if (pid == 0)
        {
            char *args[] = {command, NULL};
            if (execvp(command, args) == -1)
            {
                perror("execvp");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            wait(NULL);
        }
    }
}

/**
 * execute_commands - execute multiple commands separated by ;
 * @commands: commands to execute
 */
void execute_commands(char *commands)
{
    char *command = strtok(commands, ";");
    while (command != NULL)
    {
        execute_command(command);
        command = strtok(NULL, ";");
    }
}

/**
 * main - entry point
 * Return: 0 on success, non-zero on failure
 */
int main(void)
{
    while (1)
    {
        printf("SimpleShell> ");

        char *line = NULL;
        size_t len = 0;
        getline(&line, &len, stdin);

        char *commands = strtok(line, "\n");
        if (commands == NULL)
        {
            free(line);
            continue;
        }

        execute_commands(commands);

        free(line);
    }

    return 0;
}
