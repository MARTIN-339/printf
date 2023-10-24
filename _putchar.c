#include <unistd.h>
/**
 * _putchar - print outs a character to the standard output
 * @ch: expected character to write
 * Return: -1 on error and 1 on success
 */
int _putchar(char ch)
{
	return (write(1, &ch, 1));
}
