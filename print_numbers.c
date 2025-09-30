#include "main.h"

/**
 * print_unsigned_recursive - prints an unsigned long number
 * @n: number to print
 *
 * Return: number of chars printed, or -1 on error
 */
static int print_unsigned_recursive(unsigned long n)
{
	int count = 0, r;

	if (n / 10)
	{
		r = print_unsigned_recursive(n / 10);
		if (r == -1)
			return (-1);
		count += r;
	}
	r = _putchar((char)('0' + (n % 10)));
	if (r == -1)
		return (-1);
	return (count + r);
}

/**
 * print_number - prints a signed integer (handles INT_MIN safely)
 * @n: number to print
 *
 * Return: number of chars printed, or -1 on error
 */
int print_number(int n)
{
	long num = n;    /* widen to handle INT_MIN */
	int count = 0, r;

	if (num < 0)
	{
		r = _putchar('-');
		if (r == -1)
			return (-1);
		count += r;
		num = -num;
	}
	r = print_unsigned_recursive((unsigned long)num);
	if (r == -1)
		return (-1);
	return (count + r);
}
