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
	ssize_t chars;
	size_t n = 0;

	while (1)
	{
         	free_double_buff(cmd_line);
		printprompt();


		chars = getline(&line, &n, stdin);
		getline_check(chars);
		cmd_line = split_string(line, " "); /*free memory*/

		if (cmd_line == NULL || *cmd_line == NULL || **cmd_line == '\0')
		{
			perror("cmd line unsuccessful");
			continue;
		}

		path = find_path(cmd_line[0]);
		permission = permision_check(path);

		if (permission == -1)
			perror(argv[0]);
		else
			execute_cmd(cmd_line, argv);

/*		if (shell.interact != 1)
			_exit();*/
	}



	return (0);
}
