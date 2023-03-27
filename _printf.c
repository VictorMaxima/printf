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
			case '%':
			_putchar('%');
			size++;
			break;
			}
		i += 2;
		}

		else
		{
			_putchar(*(format + i));
			size++;
			i++;
		}
	}
	va_end(args);
	return (size);
}

