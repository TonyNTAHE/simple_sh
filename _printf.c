#include "shell.h"

/**
 * _printf - prints strings.
 * @format: format string.
 * Return: zero on success.
 */
int _printf(const char *format, ...)
{
	va_list fmt;
	char *s;

	va_start(fmt, format);
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			switch (*format)
			{
				case 's':
					s = va_arg(fmt, char *);
					while (*s)
					{
						_putchar(*s);
						s++;
					}
					break;
				default:
					_putchar(*format);
					break;
			}
		}
		else
		{
			_putchar(*format);
		}
	format++;
	}
	va_end(fmt);
	return (0);
}
