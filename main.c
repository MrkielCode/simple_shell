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
	if (argc > 0)
	{
		interactive_shell_mode(argv[0]);
	}
	return (0);
}
