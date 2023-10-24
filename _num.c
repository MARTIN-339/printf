#include "main.h"

/**
 * _uns_prnt - function that prints unsigned numbers
 * @tp: arguments
 * @bffr: Array
 * @flg:  evaluates flags
 * @wdt: breadth
 * @prc: accuracy requirement
 * @sz: Size indicator
 * Return: counts of characters printed.
 */
int _uns_prnt(va_list tp, char bffr[], int flg, int wdt, int prc, int sz)
{
	unsigned long int n = va_arg(tp, unsigned long int);
	int ind = BUFFER_SIZE - 2;

	n = us_cnvrt_sz(n, sz);

	if (n == 0)
		bffr[ind--] = '0';

	bffr[BUFFER_SIZE - 1] = '\0';

	while (n > 0)
	{
		bffr[ind--] = (n % 10) + '0';
		n = n / 10;
	}

	ind++;

	return (us_wrt(0, ind, bffr, flg, wdt, prc, sz));
}

/**
 * _oct_prnt - prints octal numbers
 * @tp: arguments
 * @bffr: Array
 * @flg:  evaluates flags
 * @wdt: breadth
 * @prc: accuracy requirement
 * @sz: Size indicator
 * Return: count of characters printed
 */
int _oct_prnt(va_list tp, char bffr[], int flg, int wdt, int prc, int sz)
{
	int ind = BUFFER_SIZE - 2;
	unsigned long int n = va_arg(tp, unsigned long int);
	unsigned long int num = n;

	UNUSED(wdt);

	n = us_cnvrt_sz(n, sz);

	if (n == 0)
		bffr[ind--] = '0';

	bffr[BUFFER_SIZE - 1] = '\0';

	while (n > 0)
	{
		bffr[ind--] = (n % 8) + '0';
		n = n / 8;
	}

	if (flg & HSH && num != 0)
		bffr[ind--] = '0';

	ind++;

	return (us_wrt(0, ind, bffr, flg, wdt, prc, sz));
}

/**
 * _hex_prnt - prints in hexadecimal number
 * @tp: arguments
 * @bffr: array
 * @flg:  evaluates flags
 * @wdt: breadth
 * @prc: accuracy requirement
 * @sz: Size indicator
 * Return: count of characters printed
 */
int _hex_prnt(va_list tp, char bffr[], int flg, int wdt, int prc, int sz)
{
	return (_hexa_prnt(tp, "0123456789abcdef", bffr, flg, 'x', wdt, prc,
				sz));
}

/**
 * _hex_upp_prnt - prints upper hexadecimal number
 * @tp: arguments
 * @bffr: Array
 * @flg:  evaluates flags
 * @wdt: breadth
 * @prc: accuracy requirement
 * @sz: Size indicator
 * Return: Count of characters printed
 */
int _hex_upp_prnt(va_list tp, char bffr[], int flg, int wdt, int prc, int sz)
{
	return (_hexa_prnt(tp, "0123456789ABCDEF", bffr,	flg, 'X', wdt, prc,
				sz));
}

/**
 * _hexa_prnt - prints a hexadecimal number
 * @tp: arguments
 * @dir_to: Array
 * @bffr: array
 * @flg:  evaluates flags
 * @ch_flg: evaluates flags
 * @wdt: breadth
 * @prc: accuracy requirement
 * @sz: Size indicator
 *
 * Return: counts of printed characters
 */
int _hexa_prnt(va_list tp, char dir_to[], char bffr[], int flg, char ch_flg,
		int wdt, int prc, int sz)
{
	int ind = BUFFER_SIZE - 2;
	unsigned long int n = va_arg(tp, unsigned long int);
	unsigned long int num = n;

	UNUSED(wdt);

	n = us_cnvrt_sz(n, sz);
	if (n == 0)
		bffr[ind--] = '0';

	bffr[BUFFER_SIZE - 1] = '\0';

	while (n > 0)
	{
		bffr[ind--] = dir_to[n % 16];
		n = n / 16;
	}

	if (flg & HSH && num != 0)
	{
		bffr[ind--] = ch_flg;
		bffr[ind--] = '0';
	}

	ind++;

	return (us_wrt(0, ind, bffr, flg, wdt, prc, sz));
}
