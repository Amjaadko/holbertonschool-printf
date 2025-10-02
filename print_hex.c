#include "main.h"

/**
 * print_hex - prints an unsigned int in hexadecimal
 * @n: the number to print
 * @uppercase: flag (0 = lowercase, 1 = uppercase)
 *
 * Return: number of characters printed
 */
int print_hex(unsigned int n, int uppercase)
{
    int count = 0;
    char *hex_digits;

    if (uppercase)
        hex_digits = "0123456789ABCDEF";
    else
        hex_digits = "0123456789abcdef";

    if (n / 16)
        count += print_hex(n / 16, uppercase);

    _putchar(hex_digits[n % 16]);
    return (count + 1);
}

