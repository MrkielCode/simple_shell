#include "shell.h"
/**
 * fork_command - To fork command if true
 * @full_path: to get command or path
 * @argv: arrays of arguments
 *
 * Return: status
 */

int fork_command(char *full_path, char **argv)
{
	pid_t pid;

	pid = fork();

	if (pid < 0)
	{
		perror("fork error");
		return (-1);
	}

	if (pid == 0)
	{
		if (execve(full_path, argv, NULL) == -1)
		{
			perror("execve error");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);

		if (WIFEXITED(status))
		{
			return (WEXITSTATUS(status));
		}
		else
		{
			perror("Child process did not terminate normally.");
			return (-1);
		}
	}

	return (-1);
}
