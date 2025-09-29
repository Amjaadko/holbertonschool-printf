#include "main.h"

/**
 * handle_specifier - Handles a single format specifier
 * @spec: the specifier character
 * @args: va_list containing the arguments
 *
 * Return: number of characters printed
 */
int handle_specifier(char spec, va_list args)
{
	if (spec == 'c')
		return (print_char(args));
	if (spec == 's')
		return (print_string(args));
	if (spec == '%')
	{
		write(1, "%", 1);
		return (1);
	}

	/* unsupported specifier: print '%' and the character */
	write(1, "%", 1);
	write(1, &spec, 1);
	return (2);
}

/**
 * _printf - Custom printf function
 * @format: format string
 *
 * Return: number of characters printed, or -1 on error
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{
				va_end(args);
				return (-1);
			}
			i++;
			count += handle_specifier(format[i], args);
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}

	va_end(args);
	return (count);
}

