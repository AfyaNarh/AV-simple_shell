#include "shell.h"

/**
 * main - starting point
 * @ac: argument to be counted
 * @av: vector of the argument
 * @env: environment variables
 * Return: 0
 */
int main(int ac, char **av, char **env)
{
	if (ac == 1)
	{
		data_shell datash;

		datash._environ = env;
		datash.counter = 1;
		datash.pid = aux_itoa(getpid());

		shell_loop(&datash);
	}
	return (0);
}

