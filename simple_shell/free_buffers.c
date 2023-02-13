#include "main.h"



void free_buffer(char **buffer)
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

	free(*buffer);
}

