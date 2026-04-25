#include "main.h"
#include <stdio.h>

/**
 * error_exit - prints error messages and exits
 * @code: exit code
 * @fmt: format string
 * @arg: string argument for format
 * @fd: file descriptor for close error
 */
void error_exit(int code, const char *fmt, const char *arg, int fd)
{
	if (code == 100)
		dprintf(STDERR_FILENO, fmt, fd);
	else
		dprintf(STDERR_FILENO, fmt, arg);
	exit(code);
}

/**
 * main - copies the content of a file to another file
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	int fd_from, fd_to, n_read, n_wrote;
	char buffer[1024];

	if (ac != 3)
		error_exit(97, "Usage: cp file_from file_to\n", NULL, 0);

	fd_from = open(av[1], O_RDONLY);
	if (fd_from == -1)
		error_exit(98, "Error: Can't read from file %s\n", av[1], 0);

	fd_to = open(av[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close(fd_from);
		error_exit(99, "Error: Can't write to %s\n", av[2], 0);
	}

	while ((n_read = read(fd_from, buffer, 1024)) > 0)
	{
		n_wrote = write(fd_to, buffer, n_read);
		if (n_wrote != n_read)
		{
			close(fd_from);
			close(fd_to);
			error_exit(99, "Error: Can't write to %s\n", av[2], 0);
		}
	}

	if (n_read == -1)
		error_exit(98, "Error: Can't read from file %s\n", av[1], 0);

	if (close(fd_from) == -1)
		error_exit(100, "Error: Can't close fd %d\n", NULL, fd_from);

	if (close(fd_to) == -1)
		error_exit(100, "Error: Can't close fd %d\n", NULL, fd_to);

	return (0);
}
