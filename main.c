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

	do {

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

		status = 1;
	} while (status);

	return (EXIT_SUCCESS);
}

