#include "main.h"

/**
 * print_number - prints an integer
 * @n: number to print
 *
 * Return: number of characters printed, or -1 on error
 */
int print_number(int n)
{
	int count = 0;
	int r;

	if (n < 0)
	{
		r = _putchar('-');
		if (r == -1)
			return (-1);
		count += r;
		/* careful with INT_MIN */
		if (n / 10 != 0)
			count += print_number(-(n / 10));
		r = _putchar('0' + (-(n % 10)));
		if (r == -1)
			return (-1);
		return (count + r);
	}

	if (n / 10)
	{
		r = print_number(n / 10);
		if (r == -1)
			return (-1);
		count += r;
	}

	r = _putchar('0' + (n % 10));
	if (r == -1)
		return (-1);
	return (count + r);
}
