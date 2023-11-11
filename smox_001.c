#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <strings.h>

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
        args = malloc(sizeof(char *) * 1024);
        token = strtok(line, " \t\n");
        while(token)
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
            }
            
        }
        else
            wait(&stat);
        i = 0;
        free(args);
        
    }

}
