#include "shell.h"

/**
 * s_exit - To exit command line
 * @av: arguments variables
 * Return: void
 */

void s_exit(char **av)
{
	int result = 0;

	if (av[1] != NULL)
		result = atoi(av[1]);

	free_toks(av);
	exit(result);
}
