#include "main.h"

/**
 * _printf - the real printf function
 * @format: the format.
 * Return: printed values or char.
 */
int _printf(const char *format, ...)
{
	int index, out = 0, out_ch = 0, flg, wdt, prc, sz, ib = 0;
	va_list rcd;
	char bffr[BUFFER_SIZE];

	if (format == NULL)
		return (-1);
	va_start(rcd, format);
	for (index = 0; format[index] != '\0' && format; index++)
	{
		if (format[index] != '%')
		{
			bffr[ib++] = format[index];
			if (ib == BUFFER_SIZE)
				b_prnt(bffr, &ib);
			out_ch++;
		}
		else
		{
			b_prnt(bffr, &ib);
			flg = _flg_gt(format, &index);
			wdt = _wdt_gt(format, &index, rcd);
			sz = _sz_gt(format, &index);
			prc = _prc_gt(format, &index, rcd);
			++index;
			out = prnt_hndl(format, &index, rcd, bffr, flg, wdt,
					prc, sz);
			if (out == -1)
				return (-1);
			out_ch = out_ch + out;
		}
	}
	b_prnt(bffr, &ib);
	va_end(rcd);
	return (out_ch);
}

/**
 * b_prnt - if contents of a buffer exists, it prints them
 * @bffr: Arrays handling characters
 * @ib: index.
 */
void b_prnt(char bffr[], int *ib)
{
	if (*ib > 0)
		write(1, &bffr[0], *ib);

	*ib = 0;
}
