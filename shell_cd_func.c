#include "shell.h"

/**
 * s_cd - changes working directory
 * @av: argument array
 */

void s_cd(char **av)
{
	char *directory;

	directory = av[1];

	if (directory == NULL)
	{
		directory = getenv("HOME");
		if (directory == NULL)
		{
			_print("cd: home directory not found\n");
			return;
		}
	}
	if (chdir(directory) == -1)
	{
		perror("cd");
	}
}
