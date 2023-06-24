#include "shell.h"

/**
 * print_prompt - Prints the shell prompt.
 */
void print_prompt(void)
{
	char prompt[] = "Simple_shell$ ";

	write(STDOUT_FILENO, prompt, strlen(prompt));
}

/**
 * read_input - Reads user input from stdin.
 * @string: Pointer to the input string buffer.
 * @n: Pointer to the input string buffer size.
 *
 * Return: The number of characters read.
 */
int read_input(char **string, size_t *n)
{
	int character;

	character = getline(string, n, stdin);
	return (character);
}

/**
 * process_input - Processes the user input.
 * @string: The input string.
 */
void process_input(char *string)
{
	if (string[character - 1] == '\n')
		string[character - 1] = '\0';

	int b = 0;

	argv[b] = av_strtok(string, " ");

	while (argv[b] && b < Max_Command - 1)
	{
		b++;
		argv[b] = av_strtok(NULL, " ");
	}

	run_command(argv);
}

/**
 * prompt_command - Executes the prompt command loop.
 * @av: The command-line arguments.
 */

void prompt_command(char **av)
{
	char *string = NULL;
	size_t n = 0;
	int character;

	while (1)
	{
		print_prompt();
		character = read_input(&string, &n);

		if (character == -1)
		{
			free(string)
				exit(EXIT_FAILURE);
		}

		if (string[character - 1] == '\n')
			string[character - 1] = '\0';

		int b = 0;
		char *argv[ARG_MAX];

		argv[b] = av_strtok(string, " ");

		while (argv[b] != NULL)
		{
			b++;
			argv[b] = av_strtok(NULL, " ");
		}

		run_command(argv);
	}

	free(string);
}

