#include "shell.h"

/**
 * check_builtin - check if command exit in builtin
 * @av: argument variables
 * Return: 0 or command
 */


int check_builtin(char **av)
{
	if (!av[0])
		return (0);
	if (!strcmp(av[0], "exit"))
		s_exit(av);
	if (!strcmp(av[0], "env"))
		s_env();
	else
		return (0);

	return (1);
}

/**
 * s_exit - To exit command line
 * @av: arguments variables
 */

void s_exit(char **av)
{
	int i = 0;

	if (av[1] != NULL)
		i = atoi(av[1]);

	free_toks(av);
	free_line();
	exit(i);
}

int s_env(void)
{
	int i = 0;

	while (environ[i])
	{
		_print(environ[i]);
		_putchar('\n');
		i++;
	}
	return (0);
}
