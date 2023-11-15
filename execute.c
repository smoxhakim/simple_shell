#include "main.h"
/**
 * Executefile - executes the specified file.
 * @command_line: the file to execute.
 * @nameof: the first argv of main.
 * Return: the status of the last process.
*/
int Executefile(char *command_line, char *nameof)
{
	pid_t pid;
	char **args = NULL, **env = environ, *path;
	int num_args, stat = 0;

	if (*command_line != '\0' && *command_line != '#')
	{
		command_line = findComment(command_line);
		num_args = countArguments(command_line);
		args = createBuffer(num_args, command_line);
		path = full_path(args[0]);
		if (path != NULL)
		{
			pid = fork();
			if (pid == 0)
			{
				execve(path, args, env);
				perror(args[0]);
			}
			else if (pid > 0)
				waitpid(pid, &stat, 0);
			else
				perror("fork");
		}
		else
		{
			write(STDERR_FILENO, nameof, strlen(nameof));
			write(STDERR_FILENO, ": 1: ", 5);
			write(STDERR_FILENO, args[0], strlen(args[0]));
			write(STDERR_FILENO, ": not found\n", 12);
		}
		if (path != args[0])
			free(path);
		customFree(args);
	}
	return (stat);
}

/**
 * full_path - provides the full path of a file
 * @file_name: the file to look for
 * Return: pointer to the path of the file
*/
char *full_path(char *file_name)
{
	char right_path[BUFF_SIZE], *ptr_path, **env = environ, *paths, *f_paths;
	int i = 0;

	if (access(file_name, F_OK) == 0)
		return (file_name);
	while (env[i] != NULL)
	{
		if (_strncmp(env[i], "PATH=", 5) == 0)
		{
			paths = _strdup(env[i] + 5);
			f_paths = strtok(paths, ":");
			while (f_paths)
			{
				ptr_path = _strcpy(right_path, f_paths);
				ptr_path = _strcat(right_path, "/");
				ptr_path = _strdup(_strcat(right_path, file_name));
				if (access(ptr_path, X_OK) == 0)
				{
					free(paths);
					return (ptr_path);
				}
				free(ptr_path);
				f_paths = strtok(NULL, ":");
			}
			free(paths);
		}
		i++;
	}
	return (NULL);
}
