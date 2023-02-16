#include "main.h"

/**
 * find_path - looks for an executable in the current PATH variable
 * @cmd: the command to look for
 *
 * Return: the path to the executable file containing for execution of command
 * Or NULL, if executable file not found
 */

/*char *give_path(char *command)
{
	char *cmd_path;*/

	/*if command[0] == '/' then cmd_path = command*/

/*	cmd_path = command;
	if (stat(cmd_path, &st) == 0)
	{
		puts("entered command exists -> sending path");confirmation*/
/*		return (cmd_path);
	}
	return (NULL);
}*/

char *find_command(char *command)
{
	char **arr_path;
	char *path, *search_str, cmd[15] = "/";
	int i;
	struct stat st;


	/*create own strcat*/
	strcat(cmd, command);

	/* get PATH value */
	path = getenv("PATH");

	/* create arr of strings to separate the path directories */
	arr_path = create_arr_strings(path, ":");

	/* assigning memory for containing the command path (path + command) */
	search_str = malloc(sizeof(char) * (50 + _strlen(cmd)));

	/* change the string directory path to search for executable file */
	for (i = 0; arr_path[i] != NULL; i++)
	{
		/*strcpy(search_str, arr_path[i]);*/
		strcpy(search_str, arr_path[i]);
		strcat(search_str, cmd);

		printf("search_str: %s\n", search_str);/*test*/
		if (stat(search_str, &st) == 0)
		{
			return (search_str); /*NEED TO FREE*/
		}
		else
			continue;
	}

	perror("stat error: ");
	free(search_str);
	return (NULL);
}

char **create_arr_strings(char *full_str, char *delim)
{
	char **arr_str;
	char *fullstr_copy, *fullstr_copy2, *str_part;
	int i, str_count = 0;

	/* NEED TO CHECK IF SUCCESSFUL */
	fullstr_copy = strdup(full_str); /*NEED TO FREE*/
	fullstr_copy2 = strdup(full_str);

	str_part = strtok(fullstr_copy, delim);
	while (str_part)
	{
		str_count++;
		str_part = strtok(NULL, delim);
	}

	arr_str = malloc(sizeof(char *) * str_count);

	str_part = strtok(fullstr_copy2, delim);
	for (i = 0; i < str_count; i++)
	{
		arr_str[i] = strdup(str_part); /*malloc(sizeof(char) * _strlen());*/
		str_part = strtok(NULL, delim); /*possible memory allocation problem*/
	}
	arr_str[i] = NULL;

	free(fullstr_copy);
	free(fullstr_copy2);
	return (arr_str); /*NEED TO FREE*/
}

/**
 * sort_cmd - FIX Desc. executes the passed command using execve.
 * @cmd_line: array of pointers to strings, together containing
 * the full command line.
 *
 * Return: nothing
 */

int sort_cmd(char **cmd_line)
{
	char *command;
	
	if (cmd_line)
	{
		command = find_command(cmd_line[0]);

		/* print error message with name of program argv[0] */
		if (command == NULL)	
			return (0);

		/*chechk_builtin, check_normal, check_pipe*/
		/* simple command */
		return (2);
	}
	return (0);
}

/**
 * sort_cmd - FIX Desc. executes the passed command using execve.
 * @cmd_line: array of pointers to strings, together containing
 * the full command line.
 *
 * Return: nothing
 */

int execute_cmd(char **cmd_line)
{
	char *command;
	
	if (cmd_line)
	{
		command = find_command(cmd_line[0]);

		/* print error message with name of program argv[0] */
		if (command == NULL)	
			return (0);

		/*chechk_builtin, check_normal, check_pipe*/
		/* simple command */
		return (execve(command, cmd_line, NULL));
	}
	return (0);
}
