#include "shell.h"

/**
 * fork_command - To fork command if true
 *
 * @full_path: to get command or path
 * @argv: arrays of arguments
 *
 * Return: status;
 */

int fork_command(char *full_path, char **argv)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == -1)
	{
		perror("fork error");
		return (-1);
	}

	if (pid == 0)
	{
		status = execve(full_path, argv, environ);
		if (status == -1)
			return (-1);
	}
	else
	{
		if (waitpid(pid, &status, WUNTRACED))
		{
			perror("pid waiting error");
			return (-1);
		}
	}

	return (-1);
}
