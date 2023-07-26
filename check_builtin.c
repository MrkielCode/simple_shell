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
	else if (!strcmp(av[0], "exit"))
		s_exit(av);
	else if (!strcmp(av[0], "env"))
		s_env();
	else if (!strcmp(av[0], "cd"))
		s_cd(av);
	else if (!strcmp(av[0], "setenv"))
		s_setenv(av);
	else if (!strcmp(av[0], "unsetenv"))
		s_unsetenv(av);
	else
		return (0);

	return (1);
}
