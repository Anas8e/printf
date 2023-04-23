#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - Prints formatted output to stdout.
 * @format: A format string.
 *
 * Return: The number of characters printed (excluding the null byte used to end output to strings).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, count = 0;
	char *str_arg;
	char char_arg;

	va_start(args, format);

	/* Loop over format string */
	for (i = 0; format[i] != '\0'; i++)
	{
		/* If '%' is encountered, parse the conversion specifier */
		if (format[i] == '%')
		{
			i++;

			/* Handle conversion specifier */
			switch (format[i])
			{
				case 'c':
					char_arg = va_arg(args, int);
					putchar(char_arg);
					count++;
					break;
				case 's':
					str_arg = va_arg(args, char *);
					while (*str_arg != '\0')
					{
						putchar(*str_arg);
						str_arg++;
						count++;
					}
					break;
				case '%':
					putchar('%');
					count++;
					break;
				default:
					putchar('%');
					putchar(format[i]);
					count += 2;
					break;
			}
		}
		else
		{
			/* Print literal character */
			putchar(format[i]);
			count++;
		}
	}

	va_end(args);

	return count;
}

