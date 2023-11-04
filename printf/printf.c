#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf - Entry point
 *@format:var
 *
 * Return: Always
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count;

	va_start(args, format);
	count = 0;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					count += putchar(va_arg(args, int));
					break;
				case 's':
					{
						const char *str = va_arg(args, const char *);

						while (*str)
						{
							count += putchar(*str);
							str++;
						}
					}
					break;
				case '%':
					count += putchar('%');
					break;
				default:
					count += putchar('%');
					count += putchar(*format);
					break;
			}
		}
		else
		{
			count += putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (count);
}
