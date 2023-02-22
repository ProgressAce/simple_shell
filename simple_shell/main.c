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
		free_double_buff(cmd_line);
		free(path);
		printprompt();

		chars = getline(&line, &n, stdin);
		printf("getline pass\n");/*test*/
		if (chars == -1)
			break;
		if (chars == 1)
			continue;
		line_num++;

		/* for interactive and non-interactive shell */
		cmd_line = split_string(line, " "); /*free memory*/
		printf("split_string pass\n");/*test*/

		if (cmd_line == NULL || *cmd_line == NULL || **cmd_line == '\0')
		{
			perror("cmd line unsuccessful");
			continue;
		}

		if (builtin_cmd(cmd_line) != NULL)
			continue;
		printf("builtin_cmd pass\n");/*test*/
		printf("cmd_line[0]: %s\n", cmd_line[0]);/*test*/
		path = find_path(cmd_line[0]);
		printf("find_path pass\n");/*test*/
		if (path != NULL)
			permission = permission_check(path);
		printf("permission_check pass\n");/*test*/
		if (path != NULL && permission == 0)
			execute_cmd(path, cmd_line);
		else
			perror(argv[0]);

		printf("execute_cmd pass\n");/*test*/
		if (shell.interact == 0)
			exit(42);
	}
	/*write(STDOUT_FILENO, "\n", 1);*/
	free(line);

	return (0);
}
