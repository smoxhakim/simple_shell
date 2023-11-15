#include "main.h"
/**
 * our_strncmp - compares two strings
 * @f_str: the first string
 * @s_str: the second string
 * @n: the index
 * Return: 0 on success, -1 on error
*/
int our_strncmp(char *f_str, char *s_str, int n)
{
	int i = 0;

	while (i < n)
	{
	if (f_str[i] != s_str[i])
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

	if (_strlen(str) == 4 && our_strncmp(str, "exit", 4) == 0)
		i = 0;
	else if (_strlen(str) == 3 && our_strncmp(str, "env", 3) == 0)
		i = 1;
	return (i);
}

