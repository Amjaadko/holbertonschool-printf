#include "main.h"

/**
 * print_unknown - prints '%' and the unknown specifier
 * @c: the unknown specifier character
 *
 * Return: 2 on success, -1 on error
 */
static int print_unknown(char c)
{
	if (_putchar('%') == -1)
		return (-1);
	if (_putchar(c) == -1)
		return (-1);
	return (2);
}

/**
 * handle_percent - handles a percent sequence at format[i]
 * @f: format string
 * @i: index of the specifier (character after '%')
 * @ap: variadic list
 *
 * Return: number of chars printed, or -1 on error
 */
static int handle_percent(const char *f, int i, va_list ap)
{
	int r;

	if (f[i] == '%')
		return (_putchar('%'));

	r = handle_specifier(f[i], ap);
	if (r == -1)
		return (-1);
	if (r == -2)
		return (print_unknown(f[i]));
	return (r);
}

/**
 * _printf - produces output according to a format
 * @format: format string
 *
 * Supported: %c, %s, %%, %d, %i
 * Unknown specifier: prints '%' then the character.
 *
 * Return: number of characters printed, or -1 on error
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int i = 0, count = 0, r;

	if (format == NULL)
		return (-1);

	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			if (_putchar(format[i]) == -1)
				return (va_end(ap), -1);
			count++;
		}
		else
		{
			i++;
			if (format[i] == '\0')
				return (va_end(ap), -1);
			r = handle_percent(format, i, ap);
			if (r == -1)
				return (va_end(ap), -1);
			count += r;
		}
		i++;
	}
	va_end(ap);
	return (count);
}
