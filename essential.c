#include "main.h"

/**
 * affix_hex_cd - Affix an ASCII in the hexadecimal format to a buffer
 * @bffr: char array
 * @ind: index to start affixing from
 * @asc_cd: Code of ASCII
 * Return: Always 3.
 */
int affix_hex_cd(char asc_cd, char bffr[], int ind)
{
	int neg = -1, sxtn = 16;
	char dir_to[] = "0123456789ABCDEF";
	/* In hexadecimal format, the code is always long by 2 digits */
	if (asc_cd < 0)
		asc_cd *= neg;

	bffr[ind++] = '\\';
	bffr[ind++] = 'x';
	bffr[ind++] = dir_to[asc_cd / sxtn];
	bffr[ind] = dir_to[asc_cd % sxtn];

	return (3);
}

/**
 * num_cnvrt_sz - converts to the specified size, a number
 * @n: number to be converted
 * @sz: size indicator.
 *
 * Return: converted value of n
 */
long int num_cnvrt_sz(long int n, int sz)
{
	if (sz == SHRT_S)
		return ((short)n);
	else if (sz == LNG_S)
		return (n);

	return ((int)n);
}

/**
 * _is_dgt - checks to see if char is a digit
 * @ch: expected char to be checked
 *
 * Return: 0 is ch isn't a digit but 1 if it is
 */
int _is_dgt(char ch)
{
	if (ch <= '9' && ch >= '0')
		return (1);
	return (0);
}

/**
 * us_cnvrt_sz - converts an unsigned number to the specified size
 * @n: number expected to be converted
 * @sz: size indicator
 *
 * Return: converted number
 */
long int us_cnvrt_sz(unsigned long int n, int sz)
{
	if (sz == SHRT_S)
		return ((unsigned short)n);
	else if (sz == LNG_S)
		return (n);

	return ((unsigned int)n);
}

/**
 * _is_prntbl - checks to see if a character can be printed out.
 * @ch: character to be printed out
 *
 * Return: 1 if ch can be printed out, 0 otherwise.
 */
int _is_prntbl(char ch)
{
	if (ch < 127 && ch >= 32)
		return (1);
	return (0);
}
