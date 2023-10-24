#include "main.h"

/**
 * prnt_ptr - prints the number or value of a pointer
 * @tp: arguments
 * @bffr: array
 * @flg:  evaluates flags
 * @wdt: breadth
 * @prc: accuracy requirement
 * @sz: Size indicator
 * Return: count of characters printed
 */
int prnt_ptr(va_list tp, char bffr[], int flg, int wdt, int prc, int sz)
{
	int len = 2, pd_begin = 1, i = BUFFER_SIZE - 2;
	char ch_ext = 0, pd = ' ';
	void *ad = va_arg(tp, void *);
	unsigned long n_ad;
	char dir_to[] = "0123456789abcdef";

	UNUSED(sz);
	UNUSED(wdt);

	if (ad == NULL)
		return (write(1, "(nil)", 5));

	bffr[BUFFER_SIZE - 1] = '\0';
	UNUSED(prc);

	n_ad = (unsigned long)ad;
	while (n_ad > 0)
	{
		bffr[i--] = dir_to[n_ad % 16];
		n_ad = n_ad / 16;
		len++;
	}

	if ((flg & ZER) && !(flg & MNS))
		pd = '0';
	if (flg & PLS)
		ch_ext = '+', len++;
	else if (flg & SPC)
		ch_ext = ' ', len++;
	i++;

	return (ptr_wrt(bffr, i, len, wdt, flg, pd, ch_ext, pd_begin));
}

/**
 * _nprnt - print non printable chars' ASCII codes
 * @tp: arguments
 * @bffr: array
 * @flg:  evaluates flags
 * @wdt: breadth
 * @prc: accuracy requirement
 * @sz: Size indicator
 * Return: counts of characters printed
 */
int _nprnt(va_list tp, char bffr[], int flg, int wdt, int prc, int sz)
{
	char *s = va_arg(tp, char *);
	int ind = 0, ost = 0;

	UNUSED(wdt);
	UNUSED(prc);
	UNUSED(flg);
	UNUSED(sz);

	if (s == NULL)
		return (write(1, "(null)", 6));

	while (s[ind] != '\0')
	{
		if (_is_prntbl(s[ind]))
			bffr[ind + ost] = s[ind];
		else
			ost += affix_hex_cd(s[ind], bffr, ind + ost);
		ind++;
	}

	bffr[ind + ost] = '\0';

	return (write(1, bffr, ind + ost));
}

/**
 * rev_prnt - reversely print string
 * @tp: arguments
 * @bffr: array
 * @flg: evaluates flags
 * @wdt: breadth
 * @prc: accuracy requirement
 * @sz: Size indicator
 * Return: counts of printed characters
 */

int rev_prnt(va_list tp, char bffr[], int flg, int wdt, int prc, int sz)
{
	int ind, cnt = 0;
	char *s;

	UNUSED(flg);
	UNUSED(bffr);
	UNUSED(sz);
	UNUSED(wdt);

	s = va_arg(tp, char *);
	if (s == NULL)
	{
		UNUSED(prc);

		s = ")Null(";
	}
	for (ind = 0; s[ind]; ind++)
		;

	for (ind -= 1; ind >= 0; ind--)
	{
		char q = s[ind];

		write(1, &q, 1);
		cnt++;
	}
	return (cnt);
}

/**
 * prnt_rot13 - function that prints  string in rot13.
 * @tp: arguments
 * @bffr: array
 * @flg:  evaluates flags
 * @wdt: breadth
 * @prc: accuracy requirement
 * @sz: Size indicator
 * Return: counts of printed characters
 */
int prnt_rot13(va_list tp, char bffr[], int flg, int wdt, int prc, int sz)
{
	int cnt = 0;
	char m, *s;
	unsigned int x, y;
	char frst[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char lst[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	s = va_arg(tp, char *);
	UNUSED(bffr);
	UNUSED(wdt);
	UNUSED(prc);
	UNUSED(sz);
	UNUSED(flg);

	if (s == NULL)
		s = "(AHYY)";
	for (x = 0; s[x]; x++)
	{
		for (y = 0; frst[y]; y++)
		{
			if (frst[y] == s[x])
			{
				m = lst[y];
				write(1, &y, 1);
				cnt++;
				break;
			}
		}
		if (!frst[y])
		{
			m = s[x];
			write(1, &m, 1);
			cnt++;
		}
	}
	return (cnt);
}
