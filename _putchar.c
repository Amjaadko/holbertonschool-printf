#include <unistd.h>

/**
 * _putchar - write one character to stdout
 * @c: the character
 *
 * Return: 1 on success, -1 on error
 */
int _putchar(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}
