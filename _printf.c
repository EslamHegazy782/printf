#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * _putchar - Writes a character to stdout
 * @c: The character to be written
 * Return: On success, 1. On error, -1.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_char - Prints a character
 * @c: The character to be printed
 * Return: The number of characters printed.
 */
int print_char(char c)
{
	return (_putchar(c));
}

/**
 * print_string - Prints a string
 * @str: The string to be printed
 * Return: The number of characters printed.
 */
int print_string(const char *str)
{
	if (str == NULL)
	str = "(null)";

	int count = 0;

	while (*str)
	{
	count += _putchar(*str);
	str++;
	}

	return (count);
}

/**
 * _printf - Produces output according to a format.
 * @format: The format string containing zero or more directives.
 * Return: The number of characters printed (excluding the null byte used to
 * end output to strings).
 */
int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	int count = 0;

	while (*format)
	{
	if (*format == '%')
	{
	format++;

	switch (*format)
	{
	case 'c':
	count += print_char(va_arg(args, int));
	break;
	case 's':
	count += print_string(va_arg(args, const char *));
	break;
	case '%':
	count += _putchar('%');
	break;
	default:
	count += _putchar('%');
	count += _putchar(*format);
	break;
	}
	}
	else
	{
	count += _putchar(*format);
	}

	format++;
	}

	va_end(args);

	return (count);
}
