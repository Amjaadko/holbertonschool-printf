#include "main.h"
#include <stdarg.h>

/**
 * handle_specifier - choose function for specifier
 * @c: specifier
 * @args: arguments list
 * Return: number of chars printed
 */
int handle_specifier(char c, va_list args)
{
    char *str;
    int n;
    int count; /* <-- التصريح هنا */

    if (c == 'c')
        return (_putchar(va_arg(args, int)));

    else if (c == 's')
    {
        str = va_arg(args, char *);
        if (str == NULL)
            str = "(null)";
        count = 0;

        while (str[count] != '\0')
        {
            _putchar(str[count]);
            count++;
        }
        return (count);
    }

    else if (c == '%')
        return (_putchar('%'));

    else if (c == 'd' || c == 'i')
    {
        n = va_arg(args, int);
        return (print_number(n));
    }

    return (0);
}

