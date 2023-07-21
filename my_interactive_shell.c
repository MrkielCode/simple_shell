#include "shell.h"
/**
 * my_interactive_shell - To execute commands from terminal
 *
 * @name: name of the shell
 * Return: successfull or failed
 */

void my_interactive_shell(char *name)
{
	char **args;
	char *line;

	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
	signal(SIGTSTP, handle_sigstp);

	while (1)
	{
		prompt();

		line = read_inputs();
		if (!line || !*line)
			break;

		args = parse(line);

		if (!args || !*args)
		{
			free(line);
			free(args);
			continue;
		}

		execute_call(args, name);

		free(line);
		free(args);

	}
}
