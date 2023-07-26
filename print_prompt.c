#include "shell.h"

/**
 * print_prompt - prints prompts
 *
 */
void print_prompt(void)
{
	write(STDOUT_FILENO, "$ ", 2);
}
