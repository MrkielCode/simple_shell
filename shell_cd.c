#include "shell.h"
/**
 * s_cd - To change dir
 * @av: arrays of commad
 * Return: 0 or 1
 */

int s_cd(char **av)
{
	int result = -1;
	char cwd[PATH_MAX];

	if (av[1] == NULL)
	{
		result = chdir(getenv("HOME"));
	}
	else if (strcmp(av[1], "-") == 0)
	{
		result = chdir(getenv("OLDPWD"));
	}
	else
	{
		result = chdir(av[1]);
	}

	if (result == -1)
	{
		perror("hsh");
		return (-1);
	}
	else if (result != -1)
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	return (0);
}
