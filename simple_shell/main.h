#ifndef HSHELL
#define HSHELL

/* libraries */
#include <unistd.h> /*fork, execve*/
#include <stdio.h> /*NULL*/
#include <stdlib.h> /*malloc*/
#include <string.h> /*strtok*/

/* print_funs */
void printprompt(void);
int _putchar(char c);

/* string_funcs */
int _strlen(char *s);
char *_strdup(char *s);

/* free_buffers */
void free_buffer(char **buffer);

#endif /* HSHELL */
