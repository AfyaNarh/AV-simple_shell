#include "shell.h"


/**
 * read_wrapper - read data from a file descriptor.
 *
 * @fd: file descriptor to read from
 * @buf: buffer to store the read data
 * @count: maximum number of bytes to read
 * Return: number of bytes read, or -1 on error
 */
ssize_t read_wrapper(int fd, void *buf, size_t count)
{
	ssize_t bytes_read = read(fd, buf, count);

	return (bytes_read);
}

/**
 * write_wrapper - write data from a file descriptor.
 * @fd: file descriptor to read from
 * @buf: buffer to store the read data
 * @count: maximum number of bytes to read
 * Return: number of bytes read, or -1 on error
 */
ssize_t write_wrapper(int fd, const void *buf, size_t count)
{
	ssize_t bytes_written = write(fd, buf, count);

	return (bytes_written);
}

/**
 * exit_shell - Exit the shell with the provided status.
 * @status: exit status
 */

void exit_shell(int status)
{
	char status_str[10];
	int len = int_to_string(status, status_str);

	write_wrapper(STDOUT_FILENO, "Exiting shell with status ", 26);
	write_wrapper(STDOUT_FILENO, status_str, len);
	write_wrapper(STDOUT_FILENO, "\n", 1);
	_exit(status);
}

/**
 * main - entry point
 * Return: 0
 */

int main(void)
{
	char input[100];
	int status = 0;

	read_wrapper(STDIN_FILENO, input, sizeof(input));

	int i = 0;

	while (input[i] != '\0' && input[i] != '\n')
	{
		status = (status * 10) + (input[i] - '0');
		i++;
	}

	exit_shell(status);

	return (0);
}

