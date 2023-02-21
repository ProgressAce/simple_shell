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

/* non_interactive funcs*/
char **get_stdin_cmdline(void);
char *get_stdin_cmd(void);

/* exec funcs */
char *get_env_path(void);
char *find_path(char *command);
char *builtin_cmd(char **command);
char *standard_cmd(char *command);
char **split_string(char *full_str, char *delim);
void execute_cmd(char *pathname, char **cmd_line);

/* checker funcs */
void getline_check(int chars);
int permission_check(char *pathname);

/* free_buffers */
void free_double_buff(char **buffer);


struct shell
{
	int interact;
} shell;

#endif /* HSHELL */
