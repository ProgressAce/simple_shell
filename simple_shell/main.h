#ifndef HSHELL
#define HSHELL

extern char **environ;

/* libraries */
#include <unistd.h> /*fork, execve*/
#include <stdio.h> /*NULL*/
#include <stdlib.h> /*malloc*/
#include <string.h> /*strtok*/
#include <sys/wait.h> /*wait*/
#include <sys/stat.h> /*stat*/
#include <sys/types.h>
#include <errno.h> /*perror*/

/* print_funs */
void printprompt(void);
int _putchar(char c);

/* string_funcs */
int _strlen(char *s);
char *_strdup(char *s);

/* exec funcs */
char *get_path(void);
char *standard_command(char *command);
char **split_string(char *full_str, char *delim);
void execute_cmd(char **cmd_line, char *argv[]);

/* free_buffers */
void free_double_buff(char **buffer);


struct shell
{
	int interact;
} shell;

#endif /* HSHELL */
