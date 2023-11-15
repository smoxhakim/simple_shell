#include "main.h"

/**
 * executeCommand - Executes a command in a child process.
 * @args: An array of strings representing the
 * command and its arguments
 * Return: void
 */
void executeCommand(char **args)
{
	pid_t pid;
	int stat;

	pid = fork();

	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("./shell");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&stat);
	}
}

