#include "shell.h"

void prompt_command(char **av, char **env);

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments passed to the program.
 * @argv: An array of strings containing the command-line arguments.
 *
 * Return: 0.
 */
int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		prompt_command(argv, env);
	}

	return (0);
}

/**
 * prompt_command - Executes the prompt command loop.
 * @av: The command-line arguments.
 * @env: The environment variables.
 */
void prompt_command(char **av, char **env)
{
	char *string = NULL;
	size_t n = 0;
	int character;

	(void)av;

	while (1)
	{
		print_prompt();
		character = read_input(&string, &n);

		if (character == -1)
		{
			free(string);
			exit(EXIT_FAILURE);
		}

		process_input(string);
	}

	free(string);
}

