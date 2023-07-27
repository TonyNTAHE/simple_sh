#include  "shell.h"

/**
 * _strcpy - copies the string pointed to to another string
 * including NULL  '\0' byte.
 * @dest: destination string.
 * @src: source string.
 * Return: this will return a value.
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcmp - compares two strings.
 * @s1: first string.
 * @s2: second string.
 * Return: 0 if both strings are equal.
 *         (+) num if first string is greater than second string.
 *         (-) num if first string is less than second string.
 */
int _strcmp(char *s1, char *s2)
{
	int i;
	int f = 0;

	for (i = 0; (s1[i] || s2[i]); i++)
	{
		f = s1[i] - s2[i];
		if (f != 0)
			break;
	}
	return (f);
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strchr - locates a character in a string.
 * @s: pointer.
 * @c: character in the string.
 * Return: a pointer to the first occurence of the character
 *         c in the string s, or NULL if the character is not found.
 *         NULL if the character is not found.
 */
char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
		{
			return (s);
		}
		s++;
	}
	if (*s == c)
		return (s);
	return ('\0');
}

/**
 * _strlen - returns the length of a string.
 * @s: pointer to string.
 * Return: length.
 */
int _strlen(const char *s)
{
	int i = 0;
	int count = 0;

	while (s[i])
	{
		count++;
		i++;
	}
	return (count);
}
