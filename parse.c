#include "shell.h"

/**
 * parse - to tokenize array of information from terminal
 * @line: array of input from terminal
 * Return: tokens or NULL:
 */

char **parse(char *line)
{
	int buf_size = 64;
	int track = 0;
	char *delim = " \t\r\n\a\"", *token, **tokens;

	tokens = malloc(buf_size * sizeof(char *));

	if (!tokens)
	{
		perror("memory allocation failed");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, delim);

	while (token != NULL)
	{
		tokens[track] = token;
		track++;
		if (track >= buf_size)
		{
			buf_size += buf_size;
			tokens = realloc(tokens, buf_size * sizeof(char *));

			if (tokens == NULL)
			{
				perror("memory rellocation failed");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, delim);
	}
	tokens[track] = NULL;
	return (tokens);
}
