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
#include <fcntl.h>

/* print_funs */
void printprompt(void);

/* handle_signal */
void handle_sigint(int signum);

/* string_funcs */
int _strlen(char *s);
char *_strdup(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strncmp(char *s1, char *s2, int size);

/* env funcs */
char *get_env_path(void);
void env(void);

/* exec funcs */
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
