#include "main.h"


/**
 * _strdup - duplicates a string
 *
 * @str: string
 *
 * Return: duplicated string
 */
char *_strdup(const char *str)
{
	char *dup;
	int i, length = 0;

	if (str == NULL)
		return (NULL);
	while (str[length])
		length++;
	dup = malloc(sizeof(char) * (length + 1));
	if (dup == NULL)
		return (NULL);
	for (i = 0; i <= length; i++)
		dup[i] = str[i];
	return (dup);
}


/**
 * _isnumber - check if a string is a number
 *
 * @status: string to be checked
 *
 * Return: void
 */
int _isnumber(const char *status)
{
	if (status == NULL || status[0] == '\0')
		return (0);
	while (*status)
	{
		if (!_isdigit(*status))
			return (0);
		status++;
	}
	return (1);
}


/**
 * _isdigit - check charachter if is number
 *
 * @c: charachter
 *
 * Return: 1 if digit 0 otherwise
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
