#include "shell.h"

/**
 * free_toks - free array of memory
 * @tokens: pointers array to be free
 * Return: void
 */

void free_toks(char **tokens)
{
	int i;

	if (tokens)
	{
		for (i = 0; tokens[i] != NULL; i++)
		{
			free(tokens[i]);
		}
	}
	free(tokens);
}
