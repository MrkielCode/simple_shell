#include "shell.h"

/**
 * execute_call - To execute commads from users
 * @argv: argument variables
 * @name: name of the shell
 * Return: status
 */
int execute_call(char **argv, char *name)
{
	int status = 0, result;
	char *full_path = NULL;

	if (!argv || !*argv)
		return (-1);

	/ Check if the command is a built - in shell command
	if (check_builtin(argv))
		return (status);

	/ Check if the command is accessible in the current directory
	if (access(argv[0], X_OK) == 0)
	{
		return (fork_command(argv[0], argv));
	}
	else
	{
		/ Search for the command in the PATH envirnment variable
		full_path = search_path(argv[0]);

		if (full_path != NULL)
		{
			result = fork_command(full_path, argv);
			return (result);
		}
	}

	If the command is not found or cannot be executed, display an error
	perror(name);
	return (-1);
}
