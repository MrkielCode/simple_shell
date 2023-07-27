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

	while (1)
	{
		_write();

		line = read_inputs();
		args = parse(line);
		execute_call(args, name);

		free(line);
		free(args);
	}
}
