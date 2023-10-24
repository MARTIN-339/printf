#include "main.h"

/**
 * _prc_gt - evaluates the accuracy for printing
 * @format: string formatted
 * @ind: list to be printed
 * @rcd: arguments list.
 * Return: prc
 */
int _prc_gt(const char *format, int *ind, va_list rcd)
{
	int cui = *ind + 1, prc = -1;

	if (format[cui] != '.')
		return (prc);

	prc = 0;
	for (cui = cui + 1; format[cui] != '\0'; cui++)
	{
		if (_is_dgt(format[cui]))
		{
			prc = prc * 10;
			prc += format[cui] - '0';
		}
		else if (format[cui] == '*')
		{
			cui++;
			prc = va_arg(rcd, int);
			break;
		}
		else
			break;
	}

	*ind = cui - 1;

	return (prc);
}
