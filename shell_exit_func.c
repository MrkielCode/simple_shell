#include "shell.h"

/**
 * handle_exit - To exit command line
 * @av: arguments variables
 * Return: void
 */

int handle_exit(char **av)
{
	if (av[1] != NULL)
	{
		return (atoi(av[1]));
	}
	else
	{
		return (0);
	}
}
