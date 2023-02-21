#include "main.h"

/**
 * _strlen - determines the length of a string
 * @s: the string
 *
 * Return: the length of the string
 */

int _strlen(char *s)
{
	int len = 0;

	while (*s)
	{
		len++;
		s++;
	}

	return (len);
}


/**
 * _strdup - duplicates a string by allocating memory for a pointer to
 * point towards.
 * @s: the string to duplicate
 *
 * Return: a pointer to the duplicated string,
 * or NULL - if insuffiecient memory was available.
 */

char *_strdup(char *s)
{
	char *dup, *ptr;

	if (!s)
		return (NULL);

	/* allocate memory for str */
	dup = (char *)malloc(sizeof(char) * _strlen(s) + 1);
	if (dup == NULL)
		return ((char*) NULL);

	/* copy string s */
	ptr = dup;
	while (*s)
	{
		*ptr = *s;
		s++;
		ptr++;
	}
	*ptr = '\0';

	return (dup);
}
