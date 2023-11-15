#include "main.h"
/**
 * _strlen - determines the length of a string
 * @str: the pointer pointing to a string
 * Return: length of the string
*/
int _strlen(char *str)
{
	int len = 0;

	while (*str != '\0')
	{
		str++;
		len++;
	}
	return (len);
}
/**
 * countArguments - counts arguments from
 * the command line
 * @line: command line
 * Return: number of arguments
 */
int countArguments(char *line)
{
	int i = 0, srch_spc = 1, num_args = 0;

	while (line[i] != '\0')
	{
		if (line[i] != ' ' && srch_spc == 1)
		{
			num_args++;
			srch_spc = 0;
		}
		if (line[i + 1] == ' ')
			srch_spc = 1;
		i++;
	}
	return (num_args);
}

/**
 * _strdup - duplicates a string to another one
 * @str: the string
 * Return: buffer
 */
char *_strdup(char *str)
{
	int len = 0, j = 0;
	char *buff;

	if (!str)
		return (NULL);
	while (str[len] != '\0')
		len++;
	buff = malloc(sizeof(char) * (len + 1));
	if (!buff)
		return (NULL);
	while (str[j] != '\0')
	{
		buff[j] = str[j];
		j++;
	}
	buff[j] = '\0';
	return (buff);
}

/**
 * _strcpy - copies a string to another
 * @src: The source string
 * @dest: The destination string
 * Return: On success, the destination string
*/
char *_strcpy(char *dest, char *src)
{
	int l = 0, i;

	while (src[l] != '\0')
		l++;
	for (i = 0; i <= l; i++)
		dest[i] = src[i];
	return (dest);
}

/**
 * _strcat - concat a string to another
 * @dest: The destination string
 * @src: The source string
 * Return: On success, the resulting string
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;

	while (*dest != '\0')
	{
		dest++;
		i++;
	}
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		i++;
		src++;
	}
	*dest = '\0';
	dest -= i;
	return (dest);
}
