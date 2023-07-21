#include "shell.h"

/**
 * _putchar - to print charaters
 * @c: character to be write
 * Return: character
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _print - to print string
 * @str: characters to be printed
 */

void _print(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
}
