#include "main.h"

/**
 * print_string - prints a C-string (or (null) if NULL)
 * @args: variadic argument list
 *
 * Return: number of characters printed, or -1 on error
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0, r;

	if (str == NULL)
		str = "(null)";

	while (*str)
	{
		r = _putchar(*str++);
		if (r == -1)
			return (-1);
		count += r;
	}
	return (count);
}
