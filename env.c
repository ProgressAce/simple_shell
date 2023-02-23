#include "main.h"

/**
 * get_path - gets the PATH variable's value from the global environment
 *
 * Return: the PATH's value
 */

char *get_env_path(void)
{
	int pos = 0;
	char *path = NULL;
	char **env = NULL;

	env = environ;

	while (*env)
	{
		/*CREATE OWN STRNCMP*/
		if (_strncmp(*env, "PATH=", 5) == 0)
		{
			path = _strdup(*env);
			/* move pointer to point to the PATH'S value */
			while (*path && pos < 5)
			{
				path++;
				pos++;
			}
			break;
		}
		env++;
	}

	return (path);
}

/**
 * env - writes all environment variables to stdout
 *
 * Return: nothing
 */

void env(void)
{
	char **env = environ;
	int i = 0;

	while (env[i])
	{
		write(STDOUT_FILENO, env[i], _strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}

	env = environ;
}
