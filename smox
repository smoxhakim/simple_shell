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
    int numRead, pid, stat;

    while (1)
    {
        write(STDOUT_FILENO, "$ ", 2);
        numRead = getline(&line, &size, stdin);

        if (numRead >= 0)
        {
            line[numRead - 1] = '\0';

            args[0] = line;

            pid = fork();

            if (pid == 0)
            {
                execve(line, args, NULL);
                perror("./shell");
                exit(EXIT_FAILURE);
            }
            else if (pid > 0)
            {
                wait(&stat);
            }
        }
        else
        {
            free(line);
            break;
        }
    }

    free(line);
    return (0);
}
