#include "shell.h"


/**
 * _write - To print shell prompt
 * Return: void
 */

void _write(void)
{
	write(0, "$ ", 2);
}

/**
 * interactive_shell_mode - function for interactive mode
 * @name: program name
 *
 * Return: void
 */
void interactive_shell_mode(char *name)
{
	char *line;
	char **args;
	int status;

	while (1)
	{
		_write();

		line = read_inputs();
		args = parse(line);
		status = execute_call(args, name);

		free(line);
		free(args);
		if (status >= 0)
		{
			exit(status);
		} else
			continue;
	}
}
