#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
* _putchar - Prints a character
* @c: printed character
* Return: Number of chars printed
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * print_char - Prints a char
 * @buffer: Buffer array to handle print
 * @width: Width
 * @args: list of argumens
 * Return: Number of chars printed
 */
int print_char(va_list args, char buffer[], int width)
{
	char c = va_arg(args, int);
	int i = BUFF_SIZE - 1;

	buffer[i] = c;
	buffer[i + 1] = '\0';

	return (write(1, &buffer[i], 1));
}
/**
 * print_string - Prints a string
 * @args: List a of arguments
 * @buffer: Buffer array to handle print
 * @width: get width.
 * Return: Number of chars printed
 */
int print_string(va_list args, char buffer[], int width)
{
	char *str = va_arg(args, char *);
	int i = BUFF_SIZE - 1;

	while (*str)
	{
		buffer[i] = *str;
		str++;
		i--;
	}

	return (write(1, &buffer[i + 1], strlen(&buffer[i + 1])));
}
/**
 * print_percent - Prints a percent sign
 * @args: Lista of arguments
 * @buffer: Buffer array to handle print
 * Return: Number of chars printed
 */
int print_percent(va_list args, char buffer[])
{
	UNUSED(args);
	int i = BUFF_SIZE - 2;

	buffer[i] = '%';
	buffer[i + 1] = '\0';

	return (write(1, &buffer[i], 1));
}

/**
 * print_integer - Print int
 * @args: Lista of arguments
 * @buffer: Buffer array to handle print
 * @width: get width.
 * Return: Number of chars printed
 */
int print_integer(va_list args, char buffer[], int width)
{
	return (print_decimal(args, buffer, width));
}
