#include "main.h"
/**
 * prnt_hndl - prints an argument
 * @frmt: string
 * @rcd: list.
 * @i: index
 * @bffr: array handling
 * @flg: evaluates the flags
 * @wdt: the breadth
 * @prc: accuracy requirement
 * @sz: Size indicator
 * Return: 2 or 1;
 */
int prnt_hndl(const char *frmt, int *i, va_list rcd, char bffr[], int flg,
		int wdt, int prc, int sz)
{
	int ind, len = 0, out_ch = -1;
	fm_t tp_frmt[] = {
		{'c', chr_prnt}, {'s', str_prnt}, {'%', prcnt_prnt},
		{'i', _int_prnt}, {'d', _int_prnt}, {'b', _bin_prnt},
		{'u', _uns_prnt}, {'o', _oct_prnt}, {'x', _hex_prnt},
		{'X', _hex_upp_prnt}, {'p', prnt_ptr}, {'S', _nprnt},
		{'r', rev_prnt}, {'R', prnt_rot13}, {'\0', NULL}
	};
	for (ind = 0; tp_frmt[ind].frmt != '\0'; ind++)
		if (frmt[*i] == tp_frmt[ind].frmt)
			return (tp_frmt[ind].f(rcd, bffr, flg, wdt, prc, sz));

	if (tp_frmt[ind].frmt == '\0')
	{
		if (frmt[*i] == '\0')
			return (-1);
		len = len + write(1, "%%", 1);
		if (frmt[*i - 1] == ' ')
			len = len + write(1, " ", 1);
		else if (wdt)
		{
			--(*i);
			while (frmt[*i] != '%' && frmt[*i] != ' ')
				--(*i);
			if (frmt[*i] == ' ')
				--(*i);
			return (1);
		}
		len = len + write(1, &frmt[*i], 1);
		return (len);
	}
	return (out_ch);
}
