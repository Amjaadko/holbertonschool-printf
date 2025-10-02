#include "main.h"

/**
 * handle_specifier - dispatches to the right printer for a specifier
 * @spec: the format specifier character
 * @args: variadic list
 *
 * Return: chars printed, -1 on error, or -2 if unknown specifier
 */
int handle_specifier(char spec, va_list args)
{
		if (spec == 'u')
    return (print_unsigned(va_arg(args, unsigned int)));
		if (spec == 'o')
    return (print_octal(va_arg(args, unsigned int)));
		if (spec == 'x')
    return (print_hex(va_arg(args, unsigned int), 0));
		if (spec == 'X')
    return (print_hex(va_arg(args, unsigned int), 1));

	return (-2);
}

