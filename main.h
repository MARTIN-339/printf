#ifndef FILE_MAIN_H
#define FILE_MAIN_H

/* Header files */
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024
#define UNUSED(x) (void)(x)

#define SPC 16
#define HSH 8
#define ZER 4
#define MNS 1
#define PLS 2

#define SHRT_S 1
#define LNG_S 2

/**
 * struct frmt - operation of struct
 *
 * @frmt: the format.
 * @f: associated function.
 */
struct frmt
{
	char frmt;
	int (*f)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct frmt fm_t - operation of struct
 *
 * @frmt: the format of the structure.
 * @fm_t: The function associated.
 */
typedef struct frmt fm_t;

int _printf(const char *format, ...);
int prnt_hndl(const char *frmt, int *i, va_list rcd,
		char bffr[], int flg, int wdt, int prc, int sz);

/* Prototypes for printing characters that are non-printable */
int _nprnt(va_list tp, char bffr[], int flg, int wdt, int prc, int sz);

/* Prototypes when printing strings and chars */
int chr_prnt(va_list tp, char bffr[], int flg, int wdt, int prc, int sz);
int str_prnt(va_list tp, char bffr[], int flg, int wdt, int prc, int sz);
int prcnt_prnt(va_list tp, char bffr[], int flg, int wdt, int prc, int sz);

/* Prototypes meant for handling specifiers */
int _flg_gt(const char *format, int *ind);
int _wdt_gt(const char *format, int *ind, va_list rcd);
int _sz_gt(const char *format, int *ind);
int _prc_gt(const char *format, int *ind, va_list rcd);

/* Prototypes when printing numbers */
int _int_prnt(va_list tp, char bffr[], int flg, int wdt, int prc, int sz);
int _bin_prnt(va_list tp, char bffr[], int flg, int wdt, int prc, int sz);
int _uns_prnt(va_list tp, char bffr[], int flg, int wdt, int prc, int sz);
int _oct_prnt(va_list tp, char bffr[], int flg, int wdt, int prc, int sz);
int _hex_prnt(va_list tp, char bffr[], int flg, int wdt, int prc, int sz);
int _hex_upp_prnt(va_list tp, char bffr[], int flg, int wdt, int prc, int sz);

int _hexa_prnt(va_list tp, char dir_to[], char bffr[], int flg, char ch_flg,
		int wdt, int prc, int sz);

/* Prototype to handle printing strings in the reverse order*/
int rev_prnt(va_list tp, char bffr[], int flg, int wdt, int prc, int sz);

/* Prototype meant for handling width */
int ch_hndl_wrt(char ch, char bffr[], int flg, int wdt, int prc, int sz);
int nu_wrt(int neg_is, int in, char bffr[], int flg, int wdt, int prc, int sz);
int n2_wrt(int in, char bffr[], int flg, int wdt, int prc, int lnt, char pd,
		char ch_ext);
int ptr_wrt(char bffr[], int in, int lnt, int wdt, int flg, char pd,
		char ch_ext, int pd_begin);
int us_wrt(int neg_is, int in, char bffr[], int flg, int wdt, int prc, int sz);

/* Prototypes for file chkcon */
int _is_dgt(char);
long int us_cnvrt_sz(unsigned long int n, int sz);
int _is_prntbl(char);
long int num_cnvrt_sz(long int n, int sz);
int affix_hex_cd(char, char[], int);

/* Prototypes of function to print a string in rot13 */
int prnt_rot13(va_list tp, char bffr[], int flg, int wdt, int prc, int sz);

/* Prototype for memory address */
int prnt_ptr(va_list tp, char bffr[], int flg, int wdt, int prc, int sz);

void b_prnt(char bffr[], int *ib);

#endif
