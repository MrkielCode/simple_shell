#include "shell.h"

/**
 * handle_sigint - signal for ctrl c
 * @sig: the signal number
 * Return: void
 */

void handle_sigint(int sig)
{
	(void) sig;
	_putchar('\n');
	prompt();
}

/**
 * handle_sigquit - handle signal for /
 * @sig: the signal number
 * Return: void
 */

void handle_sigquit(int sig)
{
	(void) sig;
	_print("Quit (core dumped)\n");
	exit(EXIT_SUCCESS);
}

/**
 * handle_sigstp - handle signal  (Ctrl+Z)
 * @sig: the signal number
 * Return: void
 */

void handle_sigstp(int sig)
{
	(void) sig;
	_print("\n");
	prompt();
}
