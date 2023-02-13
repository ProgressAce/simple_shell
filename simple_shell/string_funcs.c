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
	char *sptr;
	int i;

	if (!s)
		return (NULL);

	/* allocate memory for str */
	sptr = malloc(sizeof(char *) * _strlen(s));

	/* assign characters from s to sptr */
	for (i = 0; *s; i++)
	{
		sptr[i] = *s;
		s++;
	}

	return (sptr);
}
