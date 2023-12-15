#include "main.h"

/**
 * start_process - start a new process
 *
 * @d: data input
*/

void start_process(data *d)
{
	pid_t child_pid = fork();
	int status = 0;

	if (child_pid == -1)
		goto free;
	if (child_pid == 0 && execve(d->av[0], d->av, NULL) == -1)
		goto free;
	else if (wait(&status) == -1)
		goto free;
	if (WIFEXITED(status))
		d->exit_code = WEXITSTATUS(status);
	return;
free:
	perror(d->shell_name);
	free_array(d->av);
	free(d->command);
	exit(EXIT_FAILURE);
}

/**
 * handler_sigint - Signal to handle the function
 *
 * @signal: int input
*/

void handler_sigint(int signal)
{
	(void)signal;
	exit(EXIT_FAILURE);
}

/**
 * _exec - execute command
 *
 * @d: data input
*/

void _exec(data *d)
{
	const char prompt[] = PROMPT;

	signal(SIGINT, handler_sigint);

	while (1)
	{
		if (isatty(STDIN_FILENO))
			_printf(prompt);

		read_cmd(d);
		if (_strlen(d->command) != 0)
		{
			split(d, " ");
			if (!exec_builtin(d))
			{
				_which(d);
				if (access(d->av[0], F_OK) == -1)
				{
					write(STDERR_FILENO, d->shell_name, 5);
					write(STDERR_FILENO, ": 1: ", 5);
					write(STDERR_FILENO, d->av[0], _strlen(d->av[0]));
					write(STDERR_FILENO, ": ", 2);
					write(STDERR_FILENO, "not found", 9);
					write(STDERR_FILENO, "\n", 1);
				}
				else
				{
					start_process(d);
				}
			}
			free_array(d->av);
		}
		free(d->command);
	}
}
