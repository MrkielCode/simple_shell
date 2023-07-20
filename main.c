#include "shell.h"
/**
 * main - shell entry
 * Return: void
 */

int main(void)
{
	char **args;
	char *line;
	int status;

	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
	signal(SIGTSTP, handle_sigstp);

	while (1)
	{

		line = read_inputs();

		if (!line || !*line)
			break;

		args = parse(line);

		if (!args || !*args)
		{
			free(line);
			free_toks(args);
			continue;
		}
		status = _execute(args);
		free(line);
		free_toks(args);
	}

	return (EXIT_SUCCESS);
}

