#include "main.h"

/**
 * main - the entry point for this simple shell program
 *
 * Return: 0(Success)
 */

int main(int argc, char **argv)
{
	char **cmd_line = NULL;
	char *line = NULL;
	ssize_t chars_read;
	size_t n = 0;

	while (1)
	{
 		/*free memory of string inside cmd_line as well with free_buffer func*/
         	free_double_buff(cmd_line);
		free(line);

		printprompt();

		if (argc < 1)
			return (-1);


		/*check if getline failed or reached EOF or user used Ctrl + D*/	
		chars_read = getline(&line, &n, stdin);
		/*create getline check*/
		if (chars_read == -1)
			exit(1);
		if (chars_read == 1)
			continue;

		cmd_line = split_string(line, " "); /*free memory*/

		if (*cmd_line == NULL || cmd_line == NULL)
		{
			perror("cmd line unsuccessful");
			continue;
		}

		execute_cmd(cmd_line, argv);

/*		if (shell.interact != 1)
			_exit();*/
	}
	return (0);
}
