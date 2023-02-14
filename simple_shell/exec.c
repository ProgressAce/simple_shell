#include "main.h"

/**
 * find_command - looks for an executable in the current PATH variable
 * @cmd: the command to look for
 *
 * Return: the path to the executable file containing for execution of command
 * Or NULL, if executable file not found
 */

char *find_command(char *command)
{
	char **arr_path;
	char *path, *search_str, *cmd;
/*	const char *const_str;*/
	int i, arr_count = 0;
	struct stat st;

	/*create own strcat*/
	cmd = malloc(sizeof(char) * (_strlen(command) + 1));
	cmd[0] = '/';
	strcat(cmd, command);

	/* get PATH value */
	path = getenv("PATH");

	/* create arr of strings to separate the path directories */
	arr_path = create_arr_strings(path, ":");
	for (i = 0; arr_path[i] != NULL; i++)
		arr_count++;

	/* assigning memory for containing the command path (path + command) */
	search_str = malloc(sizeof(char) * (20 + _strlen(cmd)));

	/* change the string directory path to search for executable file */
	for (i = 0; arr_path[i] != NULL; i++)
	{
		strcpy(search_str, arr_path[i]);
		strcat(search_str, cmd);

		printf(" arr_path: %s, search_str: %s\n", arr_path[i], search_str);/*test*/
		if (stat(search_str, &st) == 0)
		{
			free(cmd);
			return (search_str); /*NEED TO FREE*/
		}
		else
			continue;
	}

	free(cmd);
	free(search_str);
	return (NULL);
}

char **create_arr_strings(char *full_str, char *delim)
{
	char **arr_str;
	char *fullstr_copy, *str_part;
	int i, str_count = 0;

	fullstr_copy = _strdup(full_str); /*NEED TO FREE*/

	str_part = strtok(fullstr_copy, delim);
	while (str_part)
	{
		str_count++;
		str_part = strtok(NULL, delim);
	}

	arr_str = malloc(sizeof(char *) * str_count);

	str_part = strtok(full_str, delim);
	for (i = 0; i < str_count; i++)
	{
		arr_str[i] = strdup(str_part); /*malloc(sizeof(char) * _strlen());*/
		str_part = strtok(NULL, delim); /*possible memory allocation problem*/
	}
	arr_str[i] = NULL;

	return (arr_str); /*NEED TO FREE*/
}

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
		command = find_command(cmd_line[0]);

		if (command == NULL)
			/* print error message with name of program argv[0] */
			perror("PROGRAM_NAME: 1: %s: not found");
		else
		{

			if (execve(command, cmd_line, NULL) == -1)
				perror("Error occured while executing command");
		}
	}
}
