#include "shell.h"

/**
 * s_exit - To exit command line
 * @av: arguments variables
 * Return: void
 */

void handle_exit(char **av)
{
	int status = 0;

	if (av[1] != NULL)
	{
		status = atoi(av[1]);
	}
	free_toks(av);
	exit(status);
}
