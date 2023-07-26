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

	if (pid < 0)
	{
		_print("fork error");
		return (-1);
	}

	if (pid == -1)
	{
		perror(argv[0]);
		return (-1);
	}
	if (pid == 0)
	{
		if (execve(full_path, argv, environ) == -1)
		{
			perror(argv[0]);
			return (-1);
		}
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (-1);
}
