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
	if (spec == 'c')
		return (print_char(args));
	if (spec == 's')
		return (print_string(args));
	if (spec == 'd' || spec == 'i')
		return (print_number(va_arg(args, int)));
	if (spec == 'b')
        return (print_binary(args));

	return (-2);
}

