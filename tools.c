#include "main.h"

/**
 * _printf - print a string
 *
 * @str: string input
 */
void _printf(const char *str)
{
	if (!str)
		return;
	while (*str)
	{
		write(STDOUT_FILENO, str, 1);
		str++;
	}
}

/**
 * free_array - free arr of ptrs
 *
 * @array: arr of ptrs
 */
void free_array(char **array)
{
	int i;

	if (!array)
		return;

	for (i = 0; array[i]; i++)
	{
		free(array[i]);
		array[i] = NULL;
	}

	free(array);
}

/**
 * split - split string by a delimiter
 *
 * @d: data input
 * @delim: str input
 */

void split(data *d, const char *delim)
{
	char *token;
	int ntoken = 0;

	d->av = malloc(2 * sizeof(char *));
	if (d->av == NULL)
	{
		free(d->command);
		perror(d->shell_name);
		exit(EXIT_FAILURE);
	}
	d->av[0] = NULL;
	d->av[1] = NULL;

	token = strtok(d->command, delim);
	while (token)
	{
		d->av = _realloc(d->av, (ntoken + 2) * sizeof(char *));
		if (d->av == NULL)
			goto free;
		d->av[ntoken] = _strdup(token);
		if (d->av[ntoken] == NULL)
			goto free;
		ntoken++;
		token = strtok(NULL, delim);
	}
	d->av[ntoken] = NULL;
	return;
free:
	free_array(d->av);
	free(d->command);
	perror(d->shell_name);
	exit(EXIT_FAILURE);
}

/**
 * init_data - initialize data
 *
 * @d: data input
 * @shell_name: str input
 */

void init_data(data *d, const char *shell_name)
{
	d->command = NULL;
	d->av = NULL;
	d->shell_name = shell_name;
	d->exit_code = EXIT_SUCCESS;
	d->flag_overwrite_env = 0;
}

/**
 * read_cmd - get the command into data struct
 *
 * @d: data input
 */

void read_cmd(data *d)
{
	size_t n = 0;
	ssize_t nread;
	int i = 0;

	nread = _getline(&d->command, &n, stdin);

	if (nread == -1)
	{
		free(d->command);
		exit(EXIT_SUCCESS);
	}

	d->command[nread - 1] = '\0';
	_trim(d->command);
	/* replace hashtag with end of line we can also do it with strtok*/
	for (i = 0; d->command[i] != '\0'; i++)
	{
		if (d->command[0] == '#' || (d->command[i] == '#' &&
				d->command[i - 1] == ' '))
		{
			d->command[i] = '\0';
			break;
		}
	}
	_trim(d->command);
}
