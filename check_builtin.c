#include "shell.h"

/**
 * check_builtin - check if command exit in builtin
 * @av: argument variables
 * @p_st: the previous exit status
 * Return: 0 or command
 */

int check_builtin(char **av, int p_st)
{
	if (!av[0])
		return (0);
	if (!strcmp(av[0], "exit"))
		s_exit(av, p_st);
	if (!strcmp(av[0], "env"))
		s_env();
	else
		return (0);

	return (1);
}
