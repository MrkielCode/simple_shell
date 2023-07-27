#include "shell.h"

/**
 * s_exit - To exit command line
 * @av: arguments variables
 * @p_st: previous exit status
 * Return: void
 */

void s_exit(char **av, int p_st)
{
	int result = 0;

	if (av[1] != NULL)
		result = atoi(av[1]);
	else
		result = p_st;

	free_toks(av);
	exit(result);
}
