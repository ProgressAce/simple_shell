#include "main.h"

/**
 * print_prompt - prints the shell prompt to stdout
 * @void
 *
 * Return: nothing
 */

void printprompt(void)
{
	char *prompt = "($) ";
	int i = 0;

	while (prompt[i])
	{
		_putchar(prompt[i]);
		i++;
	}
}

/**
 * _putchar - write a character to stdout
 * @c: the character to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}
