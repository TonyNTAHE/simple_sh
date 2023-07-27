#include "shell.h"

/**
 * read_input - reads inputs from stdin.
 * @buf: buffer
 * @n: pointer the the length of chararcter readed.
 * Return: nothing is going to be returned here.
 */
void read_input(char **buf, size_t *n)
{
	ssize_t chsize = getline(buf, n, stdin);

	if (chsize == -1)
	{
		perror("An Error occurred");
		exit(EXIT_FAILURE);
	}
	else
	{
		(*buf)[chsize - 1] = '\0';
	}
}
