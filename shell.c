#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <strings.h>

int main(void)
{
	char *args[] = {NULL, NULL};
	char *line = NULL;
	size_t size;
	int  numRead, pid, stat, i;
	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		numRead = getline(&line, &size, stdin);
		if (numRead >= 0 )
		{
			args[0] = line;
			line[numRead - 1] = '\0';
			pid = fork();
			for (i = 0; i < numRead - 1; i++)
			{
				if(line[i] == '/')
				{
					break;
				}
			}

			if (pid == 0)
			{
				execve(line, args, NULL);
			}
			else if (pid > 0)
			{
				wait(&stat);
			}

			free(line);
			line = NULL;
		}
		else
		{
			free(line);
			break;
		}
	}
	return (0);
}
