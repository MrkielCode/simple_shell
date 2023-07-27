#include "shell.h"

/**
 * search_path - to lookup commands in environ;
 * @cmd: command to be search
 * Return: command or NULL;
 */

char *search_path(char *cmd)
{
	char *tok, *path, copy_path[1024];

	path = getenv("PATH");

	strcpy(copy_path, path);
	tok = strtok(copy_path, ":");

	while (tok != NULL)
	{
		static char full_path[256];

		strcpy(full_path, tok);
		strcat(full_path, "/");
		strcat(full_path, cmd);
		if (access(full_path, X_OK) == 0)
		{
			return (full_path);
		}

		tok = strtok(NULL, ":");
	}

	return (NULL);
}
