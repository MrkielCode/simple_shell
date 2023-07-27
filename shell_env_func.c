#include "shell.h"

/**
 * s_env - To display env
 * Return: void
 */
int s_env(void)
{
	int i = 0;


	while (environ[i])
	{
		_print(environ[i]);
		_putchar('\n');
		i++;
	}

	return (0);
}
