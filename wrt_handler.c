#include "main.h"

/**
 * ch_hndl_wrt - function that prints out string
 * @ch: character.
 * @bffr: Array
 * @flg:  evaluates flags.
 * @wdt: breadth.
 * @prc: accuracy requirement
 * @sz: Size indicator
 *
 * Return: counts of characters printed.
 */
int ch_hndl_wrt(char ch, char bffr[], int flg, int wdt, int prc, int sz)
{
	char pd = ' ';
	int ind = 0;

	UNUSED(sz);
	UNUSED(prc);

	if (flg & ZER)
		pd = '0';

	bffr[ind++] = ch;
	bffr[ind] = '\0';

	if (wdt > 1)
	{
		bffr[BUFFER_SIZE - 1] = '\0';
		for (ind = 0; ind < wdt - 1; ind++)
			bffr[BUFFER_SIZE - ind - 2] = pd;

		if (flg & MNS)
			return (write(1, &bffr[0], 1) +
			write(1, &bffr[BUFFER_SIZE - ind - 1], wdt - 1));
		else
			return (write(1, &bffr[BUFFER_SIZE - ind - 1], wdt - 1)
					+ write(1, &bffr[0], 1));
	}

	return (write(1, &bffr[0], 1));
}

/**
 * nu_wrt - prints a number
 * @in: index
 * @neg_is: arguments
 * @bffr: Array
 * @flg:  evaluates flags
 * @wdt: breadth.
 * @prc: accuracy requirement
 * @sz: Size indicator
 *
 * Return: counts of characters printed.
 */
int nu_wrt(int neg_is, int in, char bffr[], int flg, int wdt, int prc, int sz)
{
	int len = BUFFER_SIZE - in - 1;
	char ch_ext = 0, pd = ' ';

	UNUSED(sz);

	if ((flg & ZER) && !(flg & MNS))
		pd = '0';
	if (neg_is)
		ch_ext = '-';
	else if (flg & PLS)
		ch_ext = '+';
	else if (flg & SPC)
		ch_ext = ' ';

	return (n2_wrt(in, bffr, flg, wdt, prc,	len, pd, ch_ext));
}

/**
 * n2_wrt - print a number
 * @in: Index
 * @bffr: Array buffer
 * @flg: flags
 * @wdt: breadth
 * @prc: accuracy requirement
 * @len: length
 * @pd: padding character
 * @ch_ext: character in excess
 *
 * Return: count of printed characters.
 */
int n2_wrt(int in, char bffr[],	int flg, int wdt, int prc, int len, char pd,
		char ch_ext)
{
	int ind, strt_pd = 1;

	if (in == BUFFER_SIZE - 2 && wdt == 0 && prc == 0 && bffr[in] == '0')
		return (0);
	if (in == BUFFER_SIZE - 2 && bffr[in] == '0' && prc == 0)
		bffr[in] = pd = ' ';
	if (prc < len && prc > 0)
		pd = ' ';
	while (prc > len)
		bffr[--in] = '0', len++;
	if (ch_ext != 0)
		len++;
	if (wdt > len)
	{
		for (ind = 1; ind < wdt - len + 1; ind++)
			bffr[ind] = pd;
		bffr[ind] = '\0';
		if (flg & MNS && pd == ' ')
		{
			if (ch_ext)
				bffr[--in] = ch_ext;
			return (write(1, &bffr[in], len) + write(1, &bffr[1],
						ind - 1));
		}
		else if (pd == ' ' && !(flg & MNS))
		{
			if (ch_ext)
				bffr[--in] = ch_ext;
			return (write(1, &bffr[1], ind - 1) + write(1,
						&bffr[in], len));
		}
		else if (pd == '0' && !(flg & MNS))
		{
			if (ch_ext)
				bffr[--strt_pd] = ch_ext;
			return (write(1, &bffr[strt_pd], ind - strt_pd) +
				write(1, &bffr[in], len - (1 - strt_pd)));
		}
	}
	if (ch_ext)
		bffr[--in] = ch_ext;
	return (write(1, &bffr[in], len));
}

/**
 * us_wrt - function that prints unsigned number
 * @neg_is: value showing that the total is negative
 * @in: Index
 * @bffr: Array
 * @flg: flags
 * @wdt: breadth
 * @prc: accuracy requirment
 * @sz: Size indicator
 *
 * Return: count of characters that have been written.
 */
int us_wrt(int neg_is, int in, char bffr[], int flg, int wdt, int prc, int sz)
{
	char pd = ' ';
	int index = 0, len = BUFFER_SIZE - in - 1;

	UNUSED(sz);
	UNUSED(neg_is);
	if (prc == 0 && in == BUFFER_SIZE - 2 && bffr[in] == '0')
		return (0);
	if (prc > 0 && prc < len)
		pd = ' ';
	while (prc > len)
	{
		bffr[--in] = '0';
		len++;
	}
	if ((flg & ZER) && !(flg & MNS))
		pd = '0';
	if (wdt > len)
	{
		for (index = 0; index < wdt - len; index++)
			bffr[index] = pd;
		bffr[index] = '\0';
		if (flg & MNS)
		{
			return (write(1, &bffr[in], len) + write(1, &bffr[0],
						index));
		}
		else
		{
			return (write(1, &bffr[0], index) + write(1, &bffr[in],
						len));
		}
	}
	return (write(1, &bffr[in], len));
}

/**
 * ptr_wrt - Memory address writing
 * @bffr: Arrays
 * @in: Index
 * @len: length
 * @wdt: breadth
 * @flg: flags
 * @pd: Character padding
 * @ch_ext: extra character
 * @pd_begin: Starting padding
 *
 * Return: counts of characters written.
 */
int ptr_wrt(char bffr[], int in, int len, int wdt, int flg, char pd,
		char ch_ext, int pd_begin)
{
	int ind;

	if (wdt > len)
	{
		for (ind = 3; ind < wdt - len + 3; ind++)
			bffr[ind] = pd;
		bffr[ind] = '\0';
		if (flg & MNS && pd == ' ')
		{
			bffr[--in] = 'x';
			bffr[--in] = '0';
			if (ch_ext)
				bffr[--in] = ch_ext;
			return (write(1, &bffr[in], len) + write(1, &bffr[3],
						ind - 3));
		}
		else if (!(flg & MNS) && pd == ' ')
		{
			bffr[--in] = 'x';
			bffr[--in] = '0';
			if (ch_ext)
				bffr[--in] = ch_ext;
			return (write(1, &bffr[3], ind - 3) + write(1,
						&bffr[in], len));
		}
		else if (!(flg & MNS) && pd == '0')
		{
			if (ch_ext)
				bffr[--pd_begin] = ch_ext;
			bffr[1] = '0';
			bffr[2] = 'x';
			return (write(1, &bffr[pd_begin], ind - pd_begin) +
				write(1, &bffr[in], len - (1 - pd_begin) - 2));
		}
	}
	bffr[--in] = 'x';
	bffr[--in] = '0';
	if (ch_ext)
		bffr[--in] = ch_ext;
	return (write(1, &bffr[in], BUFFER_SIZE - in - 1));
}
