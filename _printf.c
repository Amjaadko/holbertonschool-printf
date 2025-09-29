#include "main.h"

/**
 * _printf - Custom printf function
 * @format: format string
 *
 * Return: number of characters printed, or -1 if error
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

	if (format == NULL) /* ✅ شرط لو الفورمات NULL */
		return (-1);

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				count += print_char(args);
			else if (format[i] == 's')
				count += print_string(args);
			else if (format[i] == '%')
			{
				write(1, "%", 1);
				count++;
			}
			else
			{
				/* لو specifier غير مدعوم: اطبعي % والحرف نفسه */
				write(1, "%", 1);
				write(1, &format[i], 1);
				count += 2;
			}
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}

	va_end(args);
	return (count);
}

