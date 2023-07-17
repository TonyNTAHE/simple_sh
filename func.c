#include "shell.h"
/**
 * _strlen - return len of a string.
 * @str: string.
 * Return: len.
 */
int _strlen(char *str)
{
	int len = 0;

	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}
