#ifndef MAIN_H
#define MAIN_H

#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#define BUFF_SIZE 1024

extern char **environ;

/*built in functions*/
int get_built_in(char *str);
int built_in(char *command, char *free_line, int process_status);
void printEnv(void);

/*memory fuctions*/
void customFree(char **args);
char **createBuffer(int num_args, char *command);

/*path functions*/
char *full_path(char *file_name);

/*command line and execution functions*/
char *trimSpaces(char *old_line);
int Executefile(char *command_line, char *nameof);
int countArguments(char *line);
char *findComment(char *command_line);

/*string functions*/
int _strlen(char *str);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strncmp(char *str1, char *str2, int n);

#endif /* MAIN_H */
