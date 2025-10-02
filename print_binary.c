#include "main.h"

/**
 * print_binary - prints an unsigned int as binary
 * @args: variadic list containing the unsigned int
 *
 * Return: number of characters printed
 */
int print_binary(va_list args)
{
    unsigned int n = va_arg(args, unsigned int);
    int count = 0;
    unsigned int mask = 1 << (sizeof(unsigned int) * 8 - 1);
    int started = 0;

    while (mask > 0)
    {
        if (n & mask)
        {
            _putchar('1');
            count++;
            started = 1;
        }
        else if (started)
        {
            _putchar('0');
            count++;
        }
        mask >>= 1;
    }

    if (count == 0) /* إذا كان الرقم صفر */
    {
        _putchar('0');
        count = 1;
    }

    return (count);
}

