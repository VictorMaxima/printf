#include "main.h"
#include <stdlib.h>
/**
 * _putchar - prints a char
 * @c : char to be printed
 * Return: 1 if success
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _putstr - prints a string
 * @String:  Strimg to be printed
 * Return: number of char printed
 */

int _putstr(const char *String)
{
	int i = 0;

	while (*(String + i) != '\0')
	{
		_putchar(*(String + i));
		i++;
	}
	return (i);
}

/**
 * print_int - prints an int
 * @n: number ti be printed
 * Return: numbervof chars printed
 */

int print_int(int n)
{
	int i, j;
	char *temp;
	char *result;

	temp = malloc(sizeof(char) * 10);
	result = malloc(sizeof(char) * 10);
	j = 0;
	if (n < 0)
	{
		n = -n;
		*(result) = '-';
		j = 1;
	}
	i = 0;
	while (n > 0)
	{
		*(temp + i) = n % 10 + '0';
		n /= 10;
		i++;
	}
	while (i > 0)
	{
		*(result + j) = *(temp + i - 1);
		i--;
		j++;
	}
	j = _putstr(result);
	free(temp);
	free(result);
	return (j);
}
