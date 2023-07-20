#include "shell.h"
/**
 * tokenize - user input to be tokenized;
 * @str: string pointers
 * @delim: delimeters
 * Return: NULL if failed or result if success
 */

char **tokenize(char *str, const char *delim)
{
	char *token = NULL;
	char **result = NULL;
	int k = 0;

	token = strtok(str, delim);

	while (token)
	{
		result = realloc(result, sizeof(char *) * (k + 1));
		if (result == NULL)
			return (NULL);

		result[k] = malloc(strlen(token) + 1);

		if (!(result[k]))
			return (NULL);

		strcpy(result[k], token);
		token = strtok(NULL, delim);
		k++;
	}

	result = realloc(result, (k + 1) * sizeof(char *));
	if (!result)
		return (NULL);

	result[k] = NULL;
	return (result);
}

/**
 * parse - tokenize from terminal
 * @line: input from terminal
 * Return: array of string or NULL
 */

char **parse(char *line)
{
	char **tokens = NULL;
	char *temp = NULL;
	char *delim = " \t\r\n\a";

	temp = strdup(line);
	if (temp == NULL)
	{
		_print("Memory allocation error\n");
		exit(EXIT_FAILURE);
	}

	tokens = tokenize(temp, delim);
	free(temp);

	return (tokens);
}
