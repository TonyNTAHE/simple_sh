#include "shell.h"

/**
 * main - main function.
 * Return: This will be zero.
 */
int main(void)
{
	size_t n = 0;
	char *buf = NULL;
	char *argv[MAX_ARGUMENTS];
	pid_t child_pid;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			print_prompt();
		}
		read_input(&buf, &n);
		if (_strcmp(buf, "exit") == 0)
		{
			exit(0);
		}
		parse_input(buf, argv);
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (child_pid == 0)
		{
			execute_cmd(argv);
		}
		else
		{
			wait(NULL);
		}
	}
	free(buf);
	return (0);
}
