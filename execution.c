#include "main.h"

/**
 * find_path - search for the file for the given command and get its path
 * @command: the name of the command
 *
 * Return: the path to the command's file
 */

char *find_path(char *command)
{
	char *path = NULL;

	if (command == NULL)
		return (NULL);

	if (command[0] == '/')
		return (command);

	path = standard_cmd(command);

	return (path);
}


/**
 * builtin_cmd - looks for the command in the list of built-in commands
 * for this simple shell.
 * @command: the command line in the form of an array of strings
 *
 * Return: the found built-in command name
 */

char *builtin_cmd(char **command)
{
	char *list_of_builtins[5] = {
		"exit", "env", "setenv", "unsetenv", NULL
	};
	int index = 0, length;

	while (list_of_builtins[index])
	{
		length = _strlen(list_of_builtins[index]);
		if (_strncmp(command[0], list_of_builtins[index], length) == 0)
			break;

		index++;
	}

	switch (index)
	{
		case 0:
			free_double_buff(command);
			exit(0);

		case 1:
			env();
/*
 *		case 2:
 *			setenv(...);
 *
 *		case 3:
 *			unsetenv(...);
 */
	}

	return (list_of_builtins[index]);
}


/**
 * standard_cmd - looks for an executable in the current PATH variable
 * @command: the command to look for
 *
 * Return: the path to the executable file containing for execution of command
 * Or NULL, if executable file not found
 */

char *standard_cmd(char *command)
{
	char **arr_path = NULL;
	char *path = NULL, *cmd_path = NULL, *cmd = NULL;
	unsigned int i = 0;
	struct stat st;

	cmd = malloc(sizeof(char) * _strlen(command));
	cmd[0] = '/';
	_strcat(cmd, command);

	/* get PATH value */
	path = get_env_path();

	/* separate the path directories */
	arr_path = split_string(path, ":"); /* FREE */
	if (arr_path == NULL)
		return (NULL);

	cmd_path = malloc(sizeof(char) * (20 + _strlen(cmd))); /* FREE */

	/* change the string directory path to search for executable file */
	for (i = 0; arr_path[i] != NULL; i++)
	{
		_strcpy(cmd_path, arr_path[i]);
		_strcat(cmd_path, cmd);

		if (stat(cmd_path, &st) == 0)
		{
			free_double_buff(arr_path);
			return (cmd_path); /* FREE */
		}
	}

	free(cmd);
	free(cmd_path);
	free_double_buff(arr_path);
	return (NULL);
}


/**
 * split_string - splits the string up into smaller parts according to a
 * sequence of characters and returns all the parts as an array of pointers
 * @str: the string to split
 * @delim: the sequence of the characters
 *
 * Return: pointer to the array of strings
 */

char **split_string(char *str, char *delim)
{
	char **arr_str = NULL;
	char *str_copy = NULL, *str_part = NULL;
	int i, str_count = 0;

	str[_strlen(str) - 1] = '\0';
	str_copy = _strdup(str); /* Need to Free*/
	if (str_copy == NULL)
		return (NULL);

	str_part = strtok(str_copy, delim);
	while (str_part)
	{
		str_count++;
		str_part = strtok(NULL, delim);
	}
	arr_str = malloc(sizeof(char *) * (str_count + 1));

	i = 0;
	str_part = strtok(str, delim);
	while (str_part)
	{
		arr_str[i] = _strdup(str_part);
		if (arr_str[i] == NULL)
		{
			free(str_copy);
			free_double_buff(arr_str);
			return (NULL);
		}
		str_part = strtok(NULL, delim);
		i++;
	}
	arr_str[i] = NULL;

	free(str_copy);
	return (arr_str); /* FREE IN USED FUNCTIONS */
}

/**
 * execute_cmd - executes the passed command using execve.
 * @pathname: the full path of a file
 * @cmd_line: array of pointers to strings, together containing
 * the full command line.
 *
 * Return: nothing
 */

void execute_cmd(char *pathname, char **cmd_line)
{
	char **env = NULL, *command = NULL;
	pid_t pid;
	int status;

	env = environ;

	command = pathname;

	pid = fork();
	if (pid == -1)
		perror("fork error: ");

	if (pid == 0)
	{
		execve(command, cmd_line, env);
		free(command);
		free_double_buff(cmd_line);
		exit(98);
	}
	else
		wait(&status);

	command = NULL;
	cmd_line = NULL;
}

