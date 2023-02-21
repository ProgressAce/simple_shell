#include "main.h"

/**
 * get_stdin_cmdline - get the input command line
 * from the STDIN file descriptor in the form of a double pointer.
 *
 * Return: pointer to strings of the command line, or
 * NULL on failure
 */

char **get_stdin_cmdline(void)
{
	char **cmd_line, *stdin_cmd = NULL, char *f;
	ssize_t bytes;

	/* for non-interactive shell */
	non_interact_cmd = malloc(sizeof(char) * _strlen(STDIN_FILENO) + 1);

	/* open and get the command from STDIN_FILENO */
	f = open(STDIN_FILENO, O_RDONLY);
	if (f == -1)
		return (NULL);

	bytes = read(f, non_interact_cmd, _strlen);
	non_interact_cmd[bytes] = '\0';

	close(f);

	cmd_line = split_string(stdin_cmd);
}


/**
 * get_stdin_cmd - get the input command
 * from the STDIN file descriptor in the form of a string.
 *
 * Return: string form of the just command, or
 * NULL on failure
 */

char **get_stdin_cmd(char **cmdline)
{
}
