#include "shell.h"

void command_prompt(char **av, char **env)
{
	char *string = NULL;
	size_t n = 0;
	ssize_t command;
	int status;
	const int Max_Command = 10;
	char *argv[Max_Command];
	pid_t child_pid;

	while (true)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("simple_shell$  ");
			fflush(stdout);
		}

		command = getline(&string, &n, stdin);
		if (command == -1)
		{
			free(string);
			exit(EXIT_FAILURE);
		}

		if (string[command - 1] == '\n')
		{
			string[command - 1] = '\0';
		}

		int argc = 0;
		char *token = strtok(string, " ");

		while (token != NULL && argc < Max_Command - 1)
		{
			argv[argc++] = token;
			token = strtok(NULL, " ");
		}
		argv[argc] = NULL;

		child_pid = fork();
		if (child_pid == -1)
		{
			free(string);
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
			if (execve(argv[0], argv, env) == -1)
			{
				printf("%s: No such file or directory\n", av[0]);
			}
	}
	wait(&status);
}

    free(string);
}

