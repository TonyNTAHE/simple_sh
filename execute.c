#include "shell.h"

/**
 * execute_cmd - execute command line.
 * @argv: argument passed to the program.
 * Return: well this not return anything at all.
 */
void execute_cmd(char **argv)
{
	char *path = _getenv("PATH");
	char *dir = path;

	if (argv[0][0] == '/')
	{
		execve(argv[0], argv, NULL);
		perror("Error");
		exit(EXIT_FAILURE);
	}
	while (*dir != '\0')
	{
		char cmd_path[256];
		int i = 0;

		while (*dir != '\0' && *dir != ':')
		{
			cmd_path[i++] = *dir;
			dir++;
		}
		cmd_path[i] = '/';
		_strcpy(cmd_path + i + 1, argv[0]);
		execve(cmd_path, argv, NULL);
		if (*dir == ':')
		{
			dir++;
		}
	}
	_printf("Command not found: %s\n", argv[0]);
	exit(EXIT_FAILURE);
}
