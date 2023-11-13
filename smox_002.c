#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(void)
{
    char **args = NULL;
    char *token, *line = NULL;
    size_t size = 0;
    int numRead, stat, i = 0;
    pid_t pid;

    while (1)
    {
        write(1, "$ ", 2);
        numRead = getline(&line, &size, stdin);
        if (strcmp(line, "exit\n") == 0)
        {
            free(line);
            break;
        }

        args = malloc(sizeof(char *) * 1024);
        token = strtok(line, " \t\n");
        i = 0;
        while (token)
        {
            args[i] = token;
            token = strtok(NULL, " \t\n");
            i++;
        }
        args[i] = NULL;
        pid = fork();

        if (pid == 0)
        {
            if (execve(args[0], args, NULL) == -1)
            {
                perror("execve");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            wait(&stat);
        }
        free(args);
    }


    return (numRead);
}
