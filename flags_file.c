#include "main.h"

/**
 * _flg_gt - evaluates the flags that are active
 * @format: string formatted.
 * @ind: parameter.
 * Return: returns flags:
 */
int _flg_gt(const char *format, int *ind)
{
	int i, cui, flg = 0;
	const int AR_FLG[] = {MNS, PLS, ZER, HSH, SPC, 0};
	const char CH_FLG[] = {'-', '+', '0', '#', ' ', '\0'};

	for (cui = *ind + 1; format[cui] != '\0'; cui++)
	{
		for (i = 0; CH_FLG[i] != '\0'; i++)
			if (format[cui] == CH_FLG[i])
			{
				flg |= AR_FLG[i];
				break;
			}

		if (CH_FLG[i] == 0)
			break;
	}

	*ind = cui - 1;

	return (flg);
}
