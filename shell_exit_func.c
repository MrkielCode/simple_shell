#include "shell.h"

/**
 * s_exit - To exit command line
 * @av: arguments variables
 * Return: void
 */

/*
void s_exit(char **av)
{
	int result = 0;

	if (av[1] != NULL)
	{
		result = atoi(av[1]);
	}

	free_toks(av);
}
*/

void s_exit(char **av)
{
	int j, k;

	if (av[1])
	{
		k = atoi(av[1]);

		if (k <= -1)
		{
			k = 2;
		}

		free_toks(av);
		exit(k);
	}

	for (j = 0; av[j]; j++)
	{
		free(av[j]);
	}

	free(av);
	exit(0);
}
