#include "shell.h"

void prompt_command(char **av, char **env)

{
	char *string = NULL;
	size_t n = 0;
	int a, status, b;
	char *argv[Max_Command];
	pid_t child_pid;
	char prompt[] = "Simple_shell$ ";

	(void) av;

	while (1)
	{
		write(STDOUT_FILENO, prompt, strlen(prompt));
		character = getline(&string, &n, stdin);

		if (character == -1)
		{
			free(string);
			exit(EXIST_FAILURE);
		}

		a = 0;
		while (string[a])
		{
			if (string[a] == '\n')
				string[a] = '\0';
			a++;
		}

		b = 0;
		argv[b] = -mystrtok(string, " ");
		while (argv[b])
		{
			b++;
			argv[b] = _mystrtok(NULL, " ");
		}

		child_pid = fork();

		if (child_pid == -1)
		{
			free(string);
			exit(EXIT_FAILURE);
		}

		if (child_pid == 0)
		{
			if (execve(argv[0], argv, env) == -1)
			{
				char error[] = "%s: No such file or directory\n";

				write(STDOUT_FILENO, argv[0], strlen(argv[0]));
				write(STDOUT_FILENO, error, strlen(error));
			}
			exit(EXIT_FAILURE);
		}

		wait(&status);
	}

	free(string);

}



