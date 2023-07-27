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
		handle_exit(av);
	if (!strcmp(av[0], "env"))
		handle_env();
	else
		return (0);

	return (1);
}
