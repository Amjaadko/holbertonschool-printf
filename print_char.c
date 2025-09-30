#include "main.h"

/**
 * print_char - prints the next variadic argument as a character
 * @args: variadic argument list
 *
 * Return: number of characters printed (1) or -1 on error
 */
int print_char(va_list args)
{
	char c = (char)va_arg(args, int);

	return (_putchar(c));
}
