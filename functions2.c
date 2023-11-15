#include "main.h"
/**
 * _strncmp - compares two strings
 * @str1: the first string
 * @str2: the second string
 * @n: the index
 * Return: 0 on success, -1 on error
*/
int _strncmp(char *str1, char *str2, int n)
{
	int i = 0;

	while (i < n)
	{
	if (str1[i] != str2[i])
		return (-1);
	i++;
	}
	return (0);
}
/**
 * get_built_in - retrieves built-in commands.
 * @str: command string.
 * Return: 0.
 */
int get_built_in(char *str)
{
	int i = -1;

	if (_strlen(str) == 4 && _strncmp(str, "exit", 4) == 0)
		i = 0;
	else if (_strlen(str) == 3 && _strncmp(str, "env", 3) == 0)
		i = 1;
	return (i);
}

