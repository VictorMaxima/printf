#include <stdarg.h>
#include "main.h"

/**
* _printf - prints a formatted string
* @format: string to be printed
* Return: number of printed characters, or -1 on error
*/
int _printf(const char *format, ...)
{
int i, size = 0;
va_list args;

va_start(args, format);
if (!format)
return (-1);
while (format && *(format + i) != '\0')
{
if (*(format + i) == '%')
{
if (*(format + i + 1) == '\0')
return (-1);
switch (*(format + i + 1))
{
case 'd':
case 'i':
size += print_int(va_arg(args, int));
break;
case 'c':
_putchar(va_arg(args, int)), size++;
break;
case 's':
size += _putstr(va_arg(args, char *));
break;
case '%':
_putchar('%'), size++;
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
