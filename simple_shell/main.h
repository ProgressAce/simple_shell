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
char *find_command(char *command);
char **create_arr_strings(char *full_str, char *delim);
int sort_cmd(char **cmd_line);
int execute_cmd(char **cmd_line);

/* free_buffers */
void free_buffer(char **buffer);

#endif /* HSHELL */
