#include "shell.h"

/**
 * read_inputs - read input from terminal
 * Return: input from terminal
 */

char *read_inputs(void)
{
	char *line = NULL;
	size_t buffsize = 0;
	ssize_t readbytes;

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

		return (line);
}
