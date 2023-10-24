#include "main.h"

/**
 * chr_prnt - the functions prints out a character
 * @tp: arguments list
 * @bffr: array to handle the printing
 * @flg:  evaluates the flags that are active
 * @wdt: the breadth
 * @prc: the accuracy requirement
 * @sz: Size indicator
 * Return: the counts of character printed
 */
int chr_prnt(va_list tp, char bffr[], int flg, int wdt, int prc, int sz)
{
	char ch;

	ch = va_arg(tp, int);

	return (ch_hndl_wrt(ch, bffr, flg, wdt, prc, sz));
}

/**
 * str_prnt - function that prints strings
 * @tp: argument list
 * @bffr: array to handle the printing
 * @flg: evaluates the flags that are active
 * @wdt: the breadth
 * @prc: the accuracy requirement
 * @sz: size indicator
 * Return: number of characters to be printed
 */
int str_prnt(va_list tp, char bffr[], int flg, int wdt, int prc, int sz)
{
	int len, index;
	char *s = va_arg(tp, char *);

	len = 0;
	UNUSED(sz);
	UNUSED(prc);
	UNUSED(bffr);
	UNUSED(flg);
	UNUSED(wdt);
	if (s == NULL)
	{
		s = "(null)";
		if (prc >= 6)
			s = "      ";
	}
	while (s[len] != '\0')
		len++;

	if (prc < len && prc >= 0)
		len = prc;

	if (wdt > len)
	{
		if (MNS && flg)
		{
			write(1, &s[0], len);
			for (index = wdt - len; index > 0; index--)
				write(1, " ", 1);
			return (wdt);
		}
		else
		{
			for (index = wdt - len; index > 0; index--)
				write(1, " ", 1);
			write(1, &s[0], len);
			return (wdt);
		}
	}

	return (write(1, &s, len));
}

/**
 * prcnt_prnt - function that prints a percentage sign, %
 * @tp: argument lists
 * @bffr: array handling printing
 * @flg:  evaluates the flags that are active
 * @wdt: breadth
 * @prc: accuracy requirement
 * @sz: Size indicator
 * Return: counts of character printed
 */
int prcnt_prnt(va_list tp, char bffr[],	int flg, int wdt, int prc, int sz)
{
	UNUSED(wdt);
	UNUSED(tp);
	UNUSED(bffr);
	UNUSED(flg);
	UNUSED(prc);
	UNUSED(sz);
	return (write(1, "%%", 1));
}

/**
 * _int_prnt - function that prints out integers
 * @tp: argument list
 * @bffr: array handling
 * @flg:  evaluates flags that are active
 * @wdt: the breadth
 * @prc: accuracy requirement
 * @sz: Size indicator
 * Return: counts of characters to be printed
 */
int _int_prnt(va_list tp, char bffr[], int flg, int wdt, int prc, int sz)
{
	int index = BUFFER_SIZE - 2;
	int neg_real = 0;
	long int num = va_arg(tp, long int);
	unsigned long int n;

	num = num_cnvrt_sz(num, sz);
	if (num == 0)
		bffr[index--] = '0';

	bffr[BUFFER_SIZE - 1] = '\0';
	n = (unsigned long int)num;

	if (num < 0)
	{
		n = (unsigned long int)(num * (-1));
		neg_real = 1;
	}

	while (n > 0)
	{
		bffr[index--] = (n % 10) + '0';
		n = n / 10;
	}

	index++;

	return (nu_wrt(neg_real, index, bffr, flg, wdt, prc, sz));
}

/**
 * _bin_prnt - prints a binary
 * @tp: argument list
 * @bffr: array to handler
 * @flg:  evaluates the active flags
 * @wdt: breadth
 * @prc: accuracy requirement
 * @sz: Size indicator
 * Return: counts of characters printed.
 */
int _bin_prnt(va_list tp, char bffr[], int flg, int wdt, int prc, int sz)
{
	unsigned int ab[32];
	int cnt;
	unsigned int index, num, ml, total;

	UNUSED(flg);
	UNUSED(bffr);
	UNUSED(sz);
	UNUSED(wdt);
	UNUSED(prc);

	num = va_arg(tp, unsigned int);
	ml = 2147483648;
	ab[0] = num / ml;
	for (index = 1; index < 32; index++)
	{
		ml = ml / 2;
		ab[index] = (num / ml) % 2;
	}
	for (total = 0, index = 0, cnt = 0; index < 32; index++)
	{
		total = total + ab[index];
		if (index == 31 || total)
		{
			char q = '0' + ab[index];

			write(1, &q, 1);
			cnt++;
		}
	}
	return (cnt);
}
