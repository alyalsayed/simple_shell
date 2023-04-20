#ifndef MAIN_H
#define MAIN_H

void checkalloc(void *ptr);
char **split(char *str);
char *readline(void);
void launch_shell(char **env);
void exec(char **commands, char **env);

#endif
