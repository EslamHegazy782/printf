#include "main.h"
#include <stdio.h>

/**
 * _printf - print function
 * @format: the format
 * Return: printed chars
 */

int _printf(const char *format, ...)
{
	int count = 0;
	int i = 0;
	va_list args;
	char buffer[BUFF_SIZE] = {0};

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
	if (format[i] == '%')
	{
		i++;
		if (format[i] == 'c')
			count += print_char(args, buffer, 0);
		else if (format[i] == 's')
			count += print_string(args, buffer, 0);
		else if (format[i] == '%')
			count += print_percent(args, buffer);
		else if (format[i] == 'd' || format[i] == 'i')
			count += print_decimal(args, buffer, 0);
		else
			count += _putchar(format[i]);
	}
	else
		count += _putchar(format[i]);
	i++;
	}

	count += write(1, buffer, strlen(buffer));
	va_end(args);

	return (count);
}
