#include "main.h"

/**
 * printprompt - prints the shell prompt to stdout, if the shell
 * is in interactive mode
 * @void
 *
 * Return: nothing
 */

void printprompt(void)
{
	char *prompt = "($) ";

	shell.interact = 1;

	if ((isatty(STDIN_FILENO) == 0) && (isatty(STDOUT_FILENO) == 1))
		shell.interact = 0;

	if (shell.interact == 1)
		write(STDOUT_FILENO, prompt, 4);
}


/**
 * printcommand_error - write an error message to stdout if the
 * command was not found.
 * @shell_name: name of the program
 * @command: the entered command
 *
 * Return: nothing
 */

void printcommand_error(char *shell_name, char *command) /*int line_num*/
{
	char *error_msg = NULL;

	strcat(error_msg, shell_name);
	strcat(error_msg, ": ");
	strcat(error_msg, command);
	write(STDOUT_FILENO, error_msg, _strlen(error_msg));
}
