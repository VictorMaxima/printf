#include <stdarg.h>
#include "main.h"

/**
 * _printf - prints a formatted string
 * @format: string to be printed
 * Return: number of printed characters
 */

int _printf(const char *format, ...)
{
	int i, size;
	va_list args;

	va_start(args, format);
	i = 0, size = 0;
	while (*(format + i) != '\0')
	{
		if (*(format + i) == '%')
		{
			switch (*(format + i + 1))
			{
				case 'd':
				case 'i':
					size +=  print_int(va_arg(args, int));
					break;
				case 'c':
					_putchar(va_arg(args, int));
					size++;
					break;
				case 's':
					size += _putstr(va_arg(args, char*));
					break;
				case '%':
					_putchar('%');
					size++;
					break;
				default:
					return (-1);
			}
		i += 2;
		}
		else
		{
			_putchar(*(format + i));
			size++, i++;
		}
	}
	va_end(args);
	return (size);
}

