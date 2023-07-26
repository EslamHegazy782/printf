#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

#define BUFF_SIZE 1024

/* Function prototypes */
int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list args, char buffer[], int width);
int print_string(va_list args, char buffer[], int width);
int print_percent(va_list args, char buffer[]);
int print_decimal(va_list args, char buffer[], int width);
int print_integer(va_list args, char buffer[], int width);
#endif
