#include "main.h"

/**
 * handle_sigint - handles what to do after the program is terminated,
 * should the user type Ctrl + c.
 * @signum: the signal num
 *
 * Return: nothing
 */

void handle_sigint(int signum)
{
	(void) signum;

	write(STDOUT_FILENO, "\n", 1);
	printprompt();
}

