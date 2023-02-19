#include "main.h"

/**
 * print_prompt - prints the shell prompt to stdout, if the shell
 * is in interactive mode
 * @void
 *
 * Return: nothing
 */

void printprompt(void)
{
	char *prompt = "($) ";

	shell.interact = 1;

	if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
		shell.interact = 0;

	if (shell.interact)
		write(STDOUT_FILENO, prompt, 4);
}
