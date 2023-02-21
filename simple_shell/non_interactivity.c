#include "main.h"

/* for non-interactive shell */

/**
 * get_stdin_cmdline - get the input command line
 * from the STDIN file descriptor in the form of a double pointer.
 *
 * Return: pointer to strings of the command line, or
 * NULL on failure
 */

char **get_stdin_cmdline(void)
{
	char **cmd_line, *stdin_cmd = NULL, *f;
	ssize_t bytes;

	stdin_cmd = malloc(sizeof(char) * _strlen(STDIN_FILENO) + 1);

	/* open and get the command from STDIN_FILENO */
	f = open(STDIN_FILENO, O_RDONLY);
	if (f == -1)
		return (NULL);

	bytes = read(f, stdin_cmd, _strlen);
	stdin_cmd[bytes] = '\0';

	close(f);

	cmd_line = split_string(stdin_cmd); /* FREE */
	return (cmd_line);
}

