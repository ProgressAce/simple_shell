#include "main.h"

/**
 * get_path - gets the PATH variable's value in the environment
 * @void
 *
 * Return: the PATH's value
 */

char *get_env_path(void)
{
	int pos = 0;
	char *path = NULL;

	while (*environ)
	{
		/*CREATE OWN STRNCMP*/
		if (strncmp(*environ, "PATH=", 5) == 0)
			path = *environ;

		/* move pointer to point to the PATH'S value */
		while(path && pos < 5)
		{
			path++;
			pos++;
		}

		environ++;
	}

	return (path);
}

/**
 * find_path - search for the file for the given command and get its path
 * @command: the name of the command
 *
 * Return: the path to the command's file
 */

char *find_path(char *command)
{
	char *path;

	if (command == NULL)
		return (NULL);

	if (command[0] == '/')
		return (command);

	if (shell.interact)
	{
		path = builtin_cmd(command);

		if (path == NULL)
			path = standard_cmd(command);
	}
	else
		path = standard_cmd(command);

	return (path);
}

/**
 * builtin_cmd - looks for the command in the list of built-in commands
 * for this simple shell.
 * @command: the command
 *
 * Return: the found built-in command name
 */

char *builtin_cmd(char *command)
{

}


/**
 * standard_cmd - looks for an executable in the current PATH variable
 * @cmd: the command to look for
 *
 * Return: the path to the executable file containing for execution of command
 * Or NULL, if executable file not found
 */

char *standard_cmd(char *command)
{
	char **arr_path;
	char *path, *search_str, cmd[15] = "/";
	int i;
	struct stat st;


	/*create own strcat*/
	strcat(cmd, command);

	/* get PATH value */
	path = get_path();

	/* separate the path directories */
	arr_path = split_string(path, ":");

	/* for containing the command path (path + command) */
	search_str = malloc(sizeof(char) * (50 + _strlen(cmd)));

	/* change the string directory path to search for executable file */
	for (i = 0; arr_path[i] != NULL; i++)
	{
		strcpy(search_str, arr_path[i]);
		strcat(search_str, cmd);

		printf("search_str: %s\n", search_str);/*test*/
		if (stat(search_str, &st) == 0)
		{
			free_double_buff(arr_path);
			return (search_str); /*FREE IN EXECUTE_CMD*/
		}
	}

	perror(command);
	free(search_str);
	free_double_buff(arr_path);
	return (NULL);
}

/**
 * split_string - splits the string up into smaller parts according to a specific
 * sequence of characters and returns all the parts as an array of pointers
 * @str: the string to split
 * @delim: the sequence of the characters
 *
 * Return: pointer to the array of strings
 */

char **split_string(char *str, char *delim)
{
	char **arr_str;
	char *str_copy, *str_part;
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
	arr_str = malloc(sizeof(char *) * str_count);

	str_part = strtok(str, delim);
	for (i = 0; i < str_count; i++)
	{
		arr_str[i] = _strdup(str_part);
		if (arr_str[i] == NULL)
		{
			free(str_copy);
			free_double_buff(arr_str);
			return (NULL);
		}

		str_part = strtok(NULL, delim);
	}
	arr_str[i] = NULL;

	free(str_copy);
	return (arr_str); /* FREE IN USED FUNCTIONS */
}

/**
 * execute_cmd - executes the passed command using execve.
 * @cmd_line: array of pointers to strings, together containing
 * the full command line.
 *
 * Return: nothing
 */

void execute_cmd(char **cmd_line, char *argv[])
{
	char *command = NULL;
	pid_t pid;
	int status;

/*	if (shell.interact)
	{*/
/*		command = builtin_command(cmd_line[0]);*/

/*		if (!command)*/
			command = standard_command(cmd_line[0]);
/*	}
	else
		command = standard_command(cmd_line[0]);*/

	/* print error message with name of program argv[0] */
	if (command != NULL)
	{
		pid = fork();
		if (pid == -1)
			perror("fork error: ");

		if (pid == 0)
		{
			execve(command, cmd_line, NULL);
			/*perror(cmd_line[0]);*/
			exit(1);
		}
		else
			wait(&status);
	}
	else
		printf("%s: Command not found\n", argv[0]);
	free(command); /* free created path */
}
