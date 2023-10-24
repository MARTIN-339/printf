#include "main.h"

/**
 * _wdt_gt - evaluates the breadth of char or strings to print
 * @format: formatted string
 * @ind: arguments list to be printed.
 * @rcd: argument list
 * Return: wdt
 */
int _wdt_gt(const char *format, int *ind, va_list rcd)
{
	int cui, wdt = 0;

	for (cui = *ind + 1; format[cui] != '\0'; cui++)
	{
		if (_is_dgt(format[cui]))
		{
			wdt = wdt * 10;
			wdt += format[cui] - '0';
		}
		else if (format[cui] == '*')
		{
			cui++;
			wdt = va_arg(rcd, int);
			break;
		}
		else
			break;
	}

	*ind = cui - 1;

	return (wdt);
}
