#include "main.h"

/**
 * main - the entry point for this simple shell program
 * @argc: the number of arguments
 * @argv: string arguments of the program
 *
 * Return: 0(Success)
 */

int main(__attribute__((unused)) int argc, char **argv)
{
	char **cmd_line = NULL, *line = NULL, *path = NULL;
	ssize_t chars;
	size_t n = 0;
	int line_num = 0, permission = -1;

	while (1)
	{
		free(path);
		free_double_buff(cmd_line);
		printprompt();
		chars = getline(&line, &n, stdin);
		if (chars == -1)
			break;
		line[chars] = '\0';
		if (chars == 1) /* only new line character entered */
		{
			path = NULL;
			cmd_line = NULL;
			continue;
		}
		if (signal(SIGINT, handle_sigint)) /* handle Ctrl+c */
			continue;
		line_num++;
		cmd_line = split_string(line, " "); /*free memory*/
		if (cmd_line == NULL || *cmd_line == NULL || **cmd_line == '\0')
			continue;
		if (builtin_cmd(cmd_line) != NULL)
			continue;
		path = find_path(cmd_line[0]);
		if (path != NULL)
			permission = permission_check(path);
		if (path != NULL && permission == 0)
			execute_cmd(path, cmd_line);
		else
			perror(argv[0]);

		if (shell.interact == 0)
			exit(42);
	}
	write(STDOUT_FILENO, "\n", 1);
	if (chars != -1)
		free(line);

	return (0);
}
