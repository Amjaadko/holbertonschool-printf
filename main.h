#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h> /* va_list */
#include <stddef.h> /* NULL */

/* public API */
int _printf(const char *format, ...);
int _putchar(char c);

/* dispatcher */
int handle_specifier(char spec, va_list args);

/* helpers used by the dispatcher */
int print_char(va_list args);
int print_string(va_list args);
int print_number(int n);

#endif /* MAIN_H */
