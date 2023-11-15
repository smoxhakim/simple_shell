#include "main.h"
/**
 * built_in - examines if the command
 * is a built-in.
 * @command: the command to check
 * @free_line: line to free if its an exit command
 * @process_status: the status of the last process
 * Return: 1 on success, 0 on failure
*/
int built_in(char *command, char *free_line, int process_status)
{
	int check_for_built_in;

	check_for_built_in = get_built_in(command);
	if (check_for_built_in == 0)
	{
		free(free_line);
		exit(WEXITSTATUS(process_status));
	}
	else if (check_for_built_in == 1)
	{
		puts_env();
		return (1);
	}
	return (0);
}

/**
 * puts_env - prints all the environment variables
*/
void puts_env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}

/**
 * look_for_comment - examines the provided
 * line for a comment.
 * @command_line: the input command line.
 * Return: the processed command line.
*/
char *look_for_comment(char *command_line)
{
	int i = 0;

	if (_strlen(command_line) >= 2)
	{
		while (command_line[i])
		{
			if (command_line[i] == '#' && command_line[i - 1] == ' ')
			{
				command_line[i - 1] = '\0';
				break;
			}
			i++;
		}
	}
	return (command_line);
}
