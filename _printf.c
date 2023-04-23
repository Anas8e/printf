#include "main.h"

/**
 * _printf - prints output according to a format.
 * @format: character string.
 *
 * Return: the number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, j = 0, count = 0;
	char *str;

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
			case 'c':
				j = va_arg(args, int);
				write(1, &j, 1);
				count++;
				break;
			case 's':
				str = va_arg(args, char *);
				if (str == NULL)
					str = "(null)";
				while (str[j])
				{
					write(1, &str[j], 1);
					j++;
					count++;
				}
				break;
			case '%':
				write(1, &format[i], 1);
				count++;
				break;
			default:
				write(1, "%", 1);
				count++;
				break;
			}
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);

	return (count);
}

