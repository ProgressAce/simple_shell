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
		char *line;
		ssize_t chars_read;
		size_t n = 0;
		int success;/* i, j, start, end */
		/*char path[6] = "PATH=";*/

		printprompt();

		/*while (environ[i])
		{
			for (j = 0; path )
		}*/

		printf("PATH: %s", environ[0]);
		/*write separate function with check conditions, getline returns -1 on failure*/
		/* free memory for both */
		chars_read = getline(&line, &n, stdin);

		/*check if getline failed or reached EOF or user used Ctrl + D*/
		if (chars_read == -1)
			exit(1);
		if (chars_read == 1)
			continue;

		
/*		execve(cmd_line[0], cmd_line, NULL);*/

		cmd_line = create_arr_strings(line, " "); /*free memory*/
		printf("%s", getenv("PATH"));

		success = execute_cmd(cmd_line);

		if (success)
			perror("execve error: ");


		printf("\n%s\n", cmd_line[0]);


/*		free_buffer(&line);
		free_buffer(&line_copy);*/
			/*free memory of string inside cmd_line as well with free_buffer func*/
		free_buffer(cmd_line);
	}
}
