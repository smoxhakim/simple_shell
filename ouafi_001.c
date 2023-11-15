#include "main.h"

/**
 * main - entry point
 *
 * Return: The number of characters read
 * from the input line.
*/
int main(void)
{
	char **args = NULL;
	char *line = NULL;
	size_t size = 0;
	size_t numRead;

	while (1)
	{
		displayPrompt();
		numRead = getline(&line, &size, stdin);

		if (strcmp(line, "exit\n") == 0)
		{
			free(line);
			break;
		}

		args = parseInput(line);
		executeCommand(args);

		free(args);
	}

	return (numRead);
}
