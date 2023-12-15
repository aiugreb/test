#include "main.h"

/**
 * main - initialize data
 * @argc: input the @argv size
 * @argv: input the array of the command line arguments
 * Return: 0.
*/

int main(int argc, char **argv)
{
	data d;
	(void)argc;
	init_data(&d, argv[0]);
	_exec(&d);

	return (0);
}
