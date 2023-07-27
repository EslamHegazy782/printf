#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * print_decimal - Prints a number in decimal notation
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @width: get width
 * Return: Number of chars printed
 */
int print_decimal(va_list args, char buffer[], int width)
{
	int num = va_arg(args, int);
	int i = BUFF_SIZE - 1;
	int is_negative = 0;

	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}

	while (num > 0)
	{
		buffer[i] = num % 10 + '0';
		num /= 10;
		i--;
	}

	if (is_negative)
	{
		buffer[i] = '-';
		i--;
	}
