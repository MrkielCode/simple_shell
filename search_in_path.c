#include "shell.h"

/**
 * search_path - to lookup commands in environ;
 * @cmd: command to be search
 * Return: command or NULL;
 */

char *search_path(char *cmd)
{
	char *tok, *full_path, *path, *copy_path;

	path = getenv("PATH");
	copy_path = strdup(path);
	tok = strtok(copy_path, ":");
	full_path = NULL;

	while (tok != NULL)
	{
		full_path = malloc(strlen(tok) + strlen(cmd) + 2);

		if (!full_path)
			return (NULL);

		strcpy(full_path, tok);
		strcat(full_path, "/");
		strcat(full_path, cmd);

		if (access(full_path, X_OK) == 0)
		{
			free(copy_path);
			return (full_path);
		}

		free(full_path);
		tok = strtok(NULL, ":");
	}

	free(copy_path);

	return (NULL);
}
