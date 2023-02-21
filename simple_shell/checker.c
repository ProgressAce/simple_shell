#include "main.h"

/**
 * getline_check - handles a few anticipated getline return values
 * viz: -1 and 1
 * @chars: number of characters of the line
 *
 * Return: nothing
 */

/*void getline_check(int chars)
{*/
	/*check if getline failed or reached EOF or user used Ctrl + D*/
/*	if (chars_read == -1)
		exit(1);
}*/

/*void special_char_check(char *line)
{
	char *symbols = "\n";

	if (strchr(*line, *symbol) == 0)
}*/

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
