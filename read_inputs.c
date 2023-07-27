#include "shell.h"

static char *last_line;

/**
 * read_inputs - read input from terminal
 * Return: input from terminal
 */

char *read_inputs(void)
{
	char *line = NULL;
	size_t buffsize = 0;
	ssize_t readbytes;

	do {
		write(0, "$ ", 2);
		readbytes = getline(&line, &buffsize, stdin);

		if (readbytes == -1)
		{
			if (feof(stdin))
			{
				free(line);
				exit(EXIT_SUCCESS);
			}
			else
			{
				free(line);
				perror("Cannot Read From Standard inputs");
				exit(EXIT_FAILURE);
			}
		}

		if (readbytes[line - 1] == '\n')
			readbytes[line - 1] = '\0';

	} while (isspace(line[0]) || line[0] == '\0');

	last_line = line;
	return (line);
}


/**
 * free_line - to free the last input
 * Return: void
 */

void free_line(void)
{
	free(last_line);

	last_line = NULL;
}
