#include "shell.h"

/**
 * _execute - To execute commads from users
 * @argv: argument variables
 * Return: status
 */
int _execute(char **argv)
{
	pid_t pid;
	int status = 0;
	char *full_path = NULL;

	if (argv == NULL || *argv == NULL)
		return (status);

	if (check_builtin(argv))
		return (status);

	pid = fork();
	if (pid < 0)
	{
		_print("fork");
		return (1);
	}
	if (pid == -1)
		perror(argv[0]), free_toks(argv), free_line();
	if (pid == 0)
	{
		if (argv[0][0] != '/')
			full_path = search_path(argv[0]);

		if (full_path == NULL)
			full_path = argv[0];

		if (execve(full_path, argv, environ) == -1)
		{
			perror(argv[0]), free_toks(argv), free_line();
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (status);
}
