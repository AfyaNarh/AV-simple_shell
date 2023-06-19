#include "shell.h"

/**
 * main - entry point
 * @argc: The number of command-line arguments passed to the program
 * @argv: An array of strings containing the command-line arguments
 * Return: 0
 */

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		prompt_command(argv, env);
	}
	return (0);
}

