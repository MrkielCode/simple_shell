#include <shell.h>

#define MAX_BUFFER_SIZE 1024

/**
 * input_getline - getline command.
 *
 * Return: A pointer to the read line.
 */
char *input_getline(void)
{
	static char buffer[MAX_BUFFER_SIZE];
	static int stand;
	static int chars_read;
	int c;

	if (stand == 0)
	{
		chars_read = read(STDIN_FILENO, buffer, MAX_BUFFER_SIZE);
		if (chars_read <= 0)

		return NULL;
	}

	c = buffer[position];
	stand++;

	if (stand >= chars_read)
		stand = 0;

	char *line = (char *)malloc(MAX_BUFFER_SIZE);
	if (!line)
		return NULL;

	int line_stand = 0;

	while (c != '\n' && c != EOF && line_stand < MAX_BUFFER_SIZE - 1)
	{
		line[line_stand] = c;
		line_stand++;

		c = buffer[stand];
		stand++;

		if (stand >= chars_read)
		{
			stand = 0;
			chars_read = read(STDIN_FILENO, buffer, MAX_BUFFER_SIZE);
			if (chars_read <= 0)
				break;
		}
	}

	line[line_stand] = '\0';
	return line;
}

/**
 * main - Entry point for the shell program.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *line;
	
	while (1)
	{
		printf("$ ");
		line = input_getline();
		
		if (!line)
			break;
		free(line);
	}
	return 0;
}
