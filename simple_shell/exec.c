#include "main.h"

/**
 * find_command - looks for an executable in the current PATH variable
 * @cmd: the command to look for
 *
 * Return:
 */



/**
 * execcmd - executes the passed command using execve.
 * @cmd_line: array of strings containing the full command line
 *
 * Return: nothing
 */

void execmd(char **cmd_line)
{
	char *command;
	
	if (cmd_line)
	{
		command = cmd_line[0];

		if (execve(command, cmd_line, NULL) == -1)
			perror("Error occured while executing command");

		/* print error message with name of program argv[0] */
	}
}
