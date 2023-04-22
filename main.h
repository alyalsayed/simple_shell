#ifndef MAIN_H
#define MAIN_H

extern char **environ;

void checkalloc(void *ptr);
char **split(char *str);
char *readline(void);
void launch_shell(void);
void exec(char **commands);
void (*get_built_in_function(char *))(char **);
void exit_shell(char **args);
/**
 * struct built_in_command - Built-in command
 * @name: Name of the command
 * @function: The function pointer to execute
 * description: A struct of functions for built-in shell command
*/
typedef struct built_in_command
{
	char *name;
	void (*function)(char **args);
} built_in_command_t;

#endif
