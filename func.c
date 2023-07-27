#include "shell.h"

/**
 * _getenv - get an environment variable.
 * @name: envirnment variable
 * Return: a pointer to teh value in the environment.
 */
char *_getenv(const char *name)
{
	size_t len = _strlen(name);

	while (*environ)
	{
		if (strncmp(name, *environ, len) == 0 && (*environ)[len] == '=')
		{
			return ((*environ) + len + 1);
		}
		environ++;
	}
	return (NULL);
}
/**
 * env - prints the environment.
 *
 * Return: nothing.
 */
void env(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		write(STDOUT_FILENO, *env, _strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}

/**
 * _strncpy - copies a string.
 * @dest: destination string.
 * @src: source string.
 * @n: number of bytes.
 * Return: dest.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	for (; i < n; i++)
		dest[i] = '\0';
	return (dest);
}
