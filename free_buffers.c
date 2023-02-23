#include "main.h"

/**
 * free_double_buff - frees the space allocated to the double pointer
 * @buffer: the double pointer
 *
 * Return: nothing
 */

void free_double_buff(char **buffer)
{
	int i;

	if (buffer == NULL || *buffer == NULL)
		return;

	i = 0;
	while (buffer[i])
	{
		free(buffer[i]);
		i++;
	}

	buffer = NULL;
}

