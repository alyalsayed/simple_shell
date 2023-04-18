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
 * @prev_status: exit status of the previous command
 * @operator: logical operator (&& or ||)
 * @next_command: next command to execute if operator is true
 * @end_of_command: pointer to the end of the current command string
 * Return: exit status of the command
 */
int execute_command(char *command, int prev_status, char *operator,
                    char **next_command, char *end_of_command)
{
    if (strcmp(command, "cd") == 0)
    {
        change_directory(strtok(NULL, " \t\n"));
        return EXIT_SUCCESS;
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
            return EXIT_FAILURE;
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
            int status;
            wait(&status);
            if (strcmp(operator, "&&") == 0 && WEXITSTATUS(status) != 0)
            {
                return WEXITSTATUS(status);
            }
            else if (strcmp(operator, "||") == 0 && WEXITSTATUS(status) == 0)
            {
                return WEXITSTATUS(status);
            }
            else if (*next_command != NULL)
            {
                // execute next command in the chain
                char *next_operator = strstr(end_of_command, operator) + 2;
                return execute_command(*next_command, WEXITSTATUS(status),
                                        next_operator, next_command, end_of_command);
            }
            else
            {
                return WEXITSTATUS(status);
            }
        }
    }
}

/**
 * execute_commands - execute multiple commands separated by ; and handle logical operators
 * @commands: commands to execute
 * Return: exit status of the last command
 */
int execute_commands(char *commands)
{
    char *command = strtok(commands, ";");
    char *next_command;
    char *end_of_command;
    int status = 0;

    while (command != NULL)
    {
        end_of_command = command + strlen(command);
        next_command = strtok(NULL, ";");
        if (next_command != NULL)
        {
            // check if next command is chained by a logical operator
            if (strstr(end_of_command, "&&") == end_of_command - 2)
            {
                status = execute_command(command, status, "&&", &next_command, end_of_command);
            }
            else if (strstr(end_of_command, "||") == end_of_command - 2)
            {
                status = execute_command(command, status, "||", &next_command, end_of_command);
            }
            else
            {
                status = execute_command(command, status, "", &next_command, end_of_command);
            }
            command = next_command;
        }
        else
        {
            status = execute_command(command, status, "", &next_command, end_of_command);
            break;
        }
    }

    return status;
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

        int status = execute_commands(commands);
        printf("Exit status: %d\n", status);

        free(line);
    }

    return 0;
}
