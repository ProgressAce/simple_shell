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
		return ((char *) NULL);

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


/**
 * _strcpy - function that copies a string pointed to by src, including
 * the terminating null byte (\0), to the buffer pointed to by dest.
 * @dest: char pointer
 * @src: src char pointer to be copied
 *
 * Return: dest pointer
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;
	int length = 0;

	/* loop through src */
	for (i = 0; src[i] != '\0'; i++)
		length++;

	/* check if src has a length greater than 0 */
	if (length > 0)
	{
		/* loop through src */
		for (i = 0; src[i] != '\0'; i++)
			dest[i] = src[i];
	}

	dest[i] = '\0';

	return (dest);
}


/**
 * _strcat - concatenates two strings. It overwrites the null byte character
 * of first string and then adds it after concatenation.
 * @dest: pointer to the first string
 * @src: pointer to the second string which will join the first string
 *
 * Return: pointer dest, which points to the resulting string
 */

char *_strcat(char *dest, char *src)
{
	/* for loop and counting */
	int i;
	int m;
	/* holding length of dest and src */
	int len_dest = 0;
	int len_src = 0;

	/* find lengths of the values which dest and src point to */
	for (i = 0; dest[i] != '\0'; i++)
		len_dest++;

	for (i = 0; src[i] != '\0'; i++)
		len_src++;

	/* join the two arrays of characters */
	m = 0;
	/* starting at terminating null byte */
	for (i = len_dest; m < len_src; i++)
	{
		dest[i] = src[m];
		m++;
	}

	/* add terminating null byte to the end */
	dest[i] = '\0';

	return (dest);
}


/**
 * _strncmp - compares the characters of two strings,
 * and returns 0 if the comparison is equal.
 * @s1: first string
 * @s2: second string
 * @size: the number of bytes of s2 to compare to
 *
 * Return: 0 if the comparison is equal, or
 * a number besides 0 if they are not equal
 */

int _strncmp(char *s1, char *s2, int size)
{
	int i;
	int result = 0;
	int len_s1 = 0;
	int len_s2 = 0;

	/* get length of s1 and s2 */
	for (i = 0; s1[i] != '\0'; i++)
		len_s1++;

	for (i = 0; s2[i] != '\0'; i++)
		len_s2++;

	/* check if s1 or s2 are empty */
	if ((len_s1 <= 0) || (len_s2 <= 0))
		return ('\0');

	i = 0;
	/* loop until s1 or s2 reaches their null byte character */
	while ((s1[i] != '\0') && (s2[i] != '\0') && (i < size))
	{
		/* check if s1 and s2 characters differ */
		if (s1[i] != s2[i])
		{
			result = (int)(s1[i] - s2[i]);
			break;
		}

		i++;
	}

	return (result);
}
