#include "main.h"

/**
 * parseInput - Parses the user input line into an array of arguments.
 * @line: The input line to be parsed.
 *
 * Return: An array of strings representing the parsed arguments.
 */

char **parseInput(char *line)
{
	char **args = malloc(sizeof(char *) * MAX_ARGS);
	char *token;
	int i = 0;

	token = strtok(line, " \t\n");
	while (token)
	{
		args[i] = token;
		token = strtok(NULL, " \t\n");
		i++;
	}
	args[i] = NULL;

	return (args);
}
