#include "shell.h"

/**
 * execute_call - To execute commads from users
 * @argv: argument variables
 * @name: name of the shell
 * @p_st: the previous exit status
 * Return: status
 */
int execute_call(char **argv, char *name, int p_st)
{
	int result;

	char *full_path = NULL;

	if (!argv || !*argv)
		return (-1);
	/*
	 * while (argv[track] != NULL)
	 * {
	 * if (strcmp(argv[track], "|") == 0)
	 * return (pipe_command(argv));
	 * track++;
	 * }
	 */


	if (check_builtin(argv, p_st))
		return (-1);

	if (access(argv[0], X_OK) == 0)
	{
		return (fork_command(argv[0], argv));
	}
	else
	{
		full_path = search_path(argv[0]);

		if (full_path != NULL)
		{
			result = fork_command(full_path, argv);
			return (result);
		}
	}

	perror(name);
	return (-1);
}
