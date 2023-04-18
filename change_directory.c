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

        char *command = strtok(line, " \t\n");
        if (command == NULL)
        {
            free(line);
            continue;
        }

        if (strcmp(command, "cd") == 0)
        {
            change_directory(strtok(NULL, " \t\n"));
        }
        else if (strcmp(command, "exit") == 0)
        {
            free(line);
            break;
        }
        else
        {
            printf("Unknown command: %s\n", command);
        }

        free(line);
    }

    return 0;
}
