#include "shell.h"

/**
 * check_builtin - check if command exit in built-ins
 * @av: Argument variables (Array of strings)
 * Return: 0 or if the command is not a built-in,
 * 1 if it is a built-in
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
