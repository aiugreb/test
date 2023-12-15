#ifndef MAIN_H
#define MAIN_H


#define PROMPT "#cisfun$ "

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <signal.h>

extern char **environ;

/**
 * struct data - holding data.
 * @av: Array of arguments
 * @command: input of the user
 * @shell_name: The name of the shell program
 * @exit_code: exit status
 * @flag_overwrite_env: 1 if the user execut setenv
 */
typedef struct data
{
	char **av;
	char *command;
	const char *shell_name;
	int exit_code;
	int flag_overwrite_env;
} data;

/**
 * struct builtin - functions handling.
 * @cmd: built in command
 * @f: function of builtin command
 */
typedef struct builtin
{
	const char *cmd;
	void (*f)(data *d);
} builtin;

/* builtin_fcts.c */
int exec_builtin(data *d);
void builtin_exit(data *d);
void builtin_env(data *d);
void builtin_setenv(data *d);
void builtin_unsetenv(data *d);
void builtin_cd(data *d);


/* tools.c */
void _printf(const char *str);
void free_array(char **array);
void split(data *d, const char *delim);
void init_data(data *d, const char *shell_name);
void read_cmd(data *d);

/* tools2.c */
void _perror(const char *str1, char *str2);
void _trim(char *str);
void *_realloc(void *ptr, unsigned int new_size);

/* execute.c */
void start_process(data *d);
void handler_sigint(int sig);
void _exec(data *d);

/* path.c */
char *_getenv(char *name);
int _which(data *d);
int _setenv(data *d, char *name, char *value);

/* string_manip.c */
unsigned int _strlen(char *s);
int _strcmp(const char *s1, const char *s2);
int _strncmp(const char *s1, const char *s2, int n);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);


/* string_manip2.c */
char *_strdup(const char *s);
int _isnumber(const char *str);
int _isdigit(int c);

/* _getline.c */
#define READ_BUF_SIZE 1024

ssize_t _getline(char **lineptr, size_t *n, FILE *stream);


#endif
