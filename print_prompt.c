#include "shell.h"

/**
 * print_prompt - prints prompts
 * Return: none on success
 */
void print_prompt(void)
{
	write(STDOUT_FILENO, "$ ", 2);
}
