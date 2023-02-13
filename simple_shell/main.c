#include "main.h"

/**
 * main - the entry point for this simple shell program
 *
 * Return: 0(Success)
 */

int main(void)
{
	while (1)
	{
		char **cmd_line;
		char *line, *line_copy, *str_part;
/*		const char *delim = " ";*/
		size_t n = 0;
		int i, chars_read, str_count = 0, pid;

		printprompt();

		/*write separate function with check conditions, getline returns -1 on failure*/
		/* free memory for both */
		chars_read = getline(&line, &n, stdin);
		line_copy = _strdup(line);

		/*check if getline failed or reached EOF or user used Ctrl + D*/
		if (chars_read == -1)
			return (-1);

		/* count the broken up command line string parts */
		str_part = strtok(line_copy, " ");
		while (str_part)
		{
			str_count++;
			str_part = strtok(NULL, " ");
		}
		
		/* place broken up command line parts into an array */
		cmd_line = malloc(sizeof(cmd_line) * str_count);
		str_part = strtok(line, " ");
		
		for (i = 0; i < str_count; i++)
		{
/*			cmd_line[i] = malloc(sizeof(char *) * _strlen(str_part));*/
			cmd_line[i] = _strdup(str_part);

			str_part = strtok(NULL, " ");
		}
		cmd_line[i] = NULL;

		pid = fork();
		if (pid == 0)
			execve(cmd_line[0], cmd_line, NULL);


/*		free_buffer(&line);
		free_buffer(&line_copy);*/
			/*free memory of string inside cmd_line as well with free_buffer func*/
/*		freeptr(cmd_line);*/
	}
}
