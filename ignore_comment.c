#include "shell.h"

/**
 * ignore_comments - ignore the comments
 * @lineptr : the giving string
 */

void ignore_comments(char *lineptr)
{
	int i;

	for (i = 0; lineptr[i] != '\0'; i++)
	{
		if (lineptr[i] == '#' && (i == 0 || loineptr[i - 1] == ' '))
		{
			lineptr[i] = '\';
			return;
		}
	}
}
