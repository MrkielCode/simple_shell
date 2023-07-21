#include "shell.h"
/**
 * main - entry point
 * @argc: argument constant
 * @argv: argument variable
 * Return: 0;
 */

int main(int argc, char *argv[])
{
	if (argc > 0)
	{
			my_interactive_shell(argv[0]);
	}
	return (0);
}
