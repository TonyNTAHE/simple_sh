#include "shell.h"

/**
 * parse_input - parsing inputs
 * @input: inputs.
 * @argv:array of character.
 * Return: nothing.
 */
void parse_input(char *input, char **argv)
{
	char *token;
	int arg_count = 0;

	token = strtok(input, " ");
	while (token != NULL && arg_count < MAX_ARGUMENTS - 1)
	{
		argv[arg_count++] = token;
		token = strtok(NULL, " ");
	}
	argv[arg_count] = NULL;
	if (arg_count > 0 && _strcmp(argv[0], "env") == 0)
	{
		env();
	}
}
