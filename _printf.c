#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * put_char - writes one character to stdout
 * @c: character to write
 *
 * Return: 1 on success, -1 on error
 */
static int put_char(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

/**
 * put_str - writes a C-string to stdout
 * @s: string to write; if NULL, prints "(null)"
 *
 * Return: number of characters written, or -1 on error
 */
static int put_str(const char *s)
{
	int i = 0;

	if (s == NULL)
		s = "(null)";

	while (s[i] != '\0')
	{
		if (write(1, &s[i], 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}

/**
 * _printf - produces output according to a format
 * @format: format string
 *
 * Supported specifiers: %c, %s, %%.
 * For any other specifier (e.g. %K, %!), prints '%' then the character.
 *
 * Return: number of characters printed, or -1 on error
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int count = 0;
	int tmp;
	int i = 0;

	if (format == NULL)
		return (-1);

	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			if (put_char(format[i]) == -1)
				return (va_end(ap), -1);
			count++;
		}
		else
		{
			i++;
			if (format[i] == '\0')
				return (va_end(ap), -1);

			if (format[i] == 'c')
			{
				if (put_char((char)va_arg(ap, int)) == -1)
					return (va_end(ap), -1);
				count++;
			}
			else if (format[i] == 's')
			{
				tmp = put_str(va_arg(ap, char *));
				if (tmp == -1)
					return (va_end(ap), -1);
				count += tmp;
			}
			else if (format[i] == '%')
			{
				if (put_char('%') == -1)
					return (va_end(ap), -1);
				count++;
			}
			else
			{
				/* Unknown specifier: print '%' then the char */
				if (put_char('%') == -1 || put_char(format[i]) == -1)
					return (va_end(ap), -1);
				count += 2;
			}
		}
		i++;
	}
	va_end(ap);
	return (count);
}
