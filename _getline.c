#include "main.h"

/**
 * _getline_helper - _getline helper function
 * @lineptr: input a string
 * @n: int input
 * Return: (0)
 */
int _getline_helper(char **lineptr, size_t *n)
{
	if (*lineptr == NULL || *n == 0)
	{
		*n = 128;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}
	return (0);
}

/**
 * _getline - reads from FILE
 * @lineptr: str input
 * @n: int input
 * @stream: FILE input
 * Return: position
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t bytesRead = 0;
	size_t position = 0, newSize;
	static char buf[READ_BUF_SIZE];
	static size_t bufSize, bufPos;
	char *newBuffer;

	if (lineptr == NULL || n == NULL || stream == NULL
		|| _getline_helper(lineptr, n) == -1)
		return (-1);
	while (1)
	{
		if (bufPos >= bufSize)
		{
			bytesRead = read(stream->_fileno, buf, READ_BUF_SIZE);
			if (bytesRead <= 0 && position == 0)
				return (-1);
			else if (bytesRead <= 0)
				break;
			bufSize = bytesRead;
			bufPos = 0;
		}
		if (position >= *n - 1)
		{
			newSize = *n * 2;
			newBuffer = realloc(*lineptr, newSize);
			if (newBuffer == NULL)
				return (-1);
			*lineptr = newBuffer;
			*n = newSize;
		}
		(*lineptr)[position++] = buf[bufPos++];
		if ((*lineptr)[position - 1] == '\n')
			break;
	}
	(*lineptr)[position] = '\0';
	return (position);
}
