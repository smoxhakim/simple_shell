#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#define MAX_ARGS 1024

char **parseInput(char *line);
void executeCommand(char **args);
void displayPrompt(void);

#endif
