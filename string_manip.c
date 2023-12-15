#include "main.h"

/**
 * _strlen - fct returns len.
 *
 * @s: str
 *
 * Return: string len
 */

unsigned int _strlen(char *s)
{
	int len;

	for (len = 0; *s != '\0'; s++)
		++len;

	return (len);
}


/**
 * _strcmp - compare two strs.
 *
 * @s1: str 1
 * @s2: str 2
 *
 * Return: compare result
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			break;
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * _strncmp - compare two strs.
 *
 * @s1: input str
 * @s2: input str 2
 * @n: input int
 *
 * Return: return (int)
 */
int _strncmp(const char *s1, const char *s2, int n)
{
	int i;
	int res = 0;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{

		if (i >= n)
			break;
		if (s1[i] != s2[i])
		{
			res = s1[i] - s2[i];
			break;
		}
	}

	return (res);
}

/**
 * *_strcpy - copies the string pointed
 * @dest: buffer
 * @src: input
 *
 * Return: ptr to dest
 */
char *_strcpy(char *dest, const char *src)
{
	char *pt_to_dest = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';
	return (pt_to_dest);
}

/**
 * _strcat - concatenates two strings.
 *
 * @dest: result
 * @src: source
 *
 * Return: ptr to dest
 */
char *_strcat(char *dest, const char *src)
{
	char *end = dest;

	while (*end != '\0')
		end++;
	while (*src != '\0')
	{
		*end = *src;
		end++;
		src++;
	}

	*end = '\0';
	return (dest);
}
