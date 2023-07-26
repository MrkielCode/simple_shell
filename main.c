#include "shell.h"
/**
 * main - entry point for the shell program
 * @argc: number of command-line argument constant
 * @argv: array of stirngs containing the command-line
 * argument variable
 * Return: Always 0;
 */

int main(int argc, char *argv[])
{
	(void)argc;

	if (isatty(STDIN_FILENO) == 0)
	{
		interactive_shell_mode(argv[0]);
	}
	else
	{
		non_interactive_shell_mode(argv[0]);
	}
	return (0);
}
