#include "shell.h"

/**
 * s_setenv - To set environmental variables
 * @av: arguments variables
 * Return: 0 or 1
 */

int s_setenv(char **av)
{
	char *variable, *value;
	int result;

	if (av[1] == NULL || av[2] == NULL)
	{
		_print("Usage: setenv VARIABLE VALUE\n");
		return (0);
	}


	variable = av[1];
	value = av[2];

	result = setenv(variable, value, 1);

	if (result != 0)
	{
		perror("setenv");
		return (0);
	}
	return (0);
}

/**
 * s_unsetenv - To unset environmental variables
 * @av: argumement variables
 * Return: 1 or 0
 */

int s_unsetenv(char **av)
{
	char *variable;
	int result;

	if (av[1] == NULL || av[2] == NULL)
	{
		_print("unsetenv VARIABLE VALUE\n");
		return (-1);
	}

	variable = av[1];

	result = unsetenv(variable);

	if (result != 0)
	{
		perror("setenv");
		return (-1);
	}
	return (0);
}
