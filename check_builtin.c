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
	if (!strcmp(av[0], "cd"))
		s_cd(av);
	else
		return (0);

	return (1);
}
