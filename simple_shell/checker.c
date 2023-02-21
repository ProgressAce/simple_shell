#include "main.h"

/**
 * permission_check - checks if the user is allowed permission to
 * execute the file.
 * @pathname: the path to the executable file
 *
 * Return: 0 for yes, -1 for no
 */

int permission_check(char *pathname)
{
	/* checks if file exists and if execute permission is allowed */
	return (access(pathname, F_OK | X_OK));
}
