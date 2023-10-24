#include "main.h"

/**
 * _sz_gt - evaluates the size to convert the argument
 * @format: string formatted where we are to print the arguments
 * @ind: argument list
 *
 * Return: sz
 */
int _sz_gt(const char *format, int *ind)
{
	int cui = *ind + 1, sz = 0;

	if (format[cui] == 'h')
		sz = SHRT_S;
	else if (format[cui] == 'l')
		sz = LNG_S;

	if (sz == 0)
		*ind = cui - 1;
	else
		*ind = cui;

	return (sz);
}
