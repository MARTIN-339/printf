#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function with limited functionality.
 * @format: Format string.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format != '%')
        {
            // Print regular characters directly to stdout
            write(1, format, 1);
            printed_chars++;
        }
        else
        {
            format++; // Move past '%'
            if (*format == 'c')
            {
                // Handle %c for characters
                char c = va_arg(args, int);
                write(1, &c, 1);
                printed_chars++;
            }
            else if (*format == 's')
            {
                // Handle %s for strings
                char *str = va_arg(args, char *);
                if (str)
                {
                    int len = 0;
                    while (str[len])
                        len++;
                    write(1, str, len);
                    printed_chars += len;
                }
                else
                {
                    write(1, "(null)", 6);
                    printed_chars += 6;
                }
            }
            else if (*format == '%')
            {
                // Handle %%
                write(1, "%", 1);
                printed_chars++;
            }
        }
        format++;
    }

    va_end(args);
    return printed_chars;
}

int main(void)
{
    char c = 'A';
    char *str = "Hello, World!";
    int len = _printf("Character: %c\nString: %s\nPercentage: %%\n", c, str);

    // Print the number of characters printed (excluding the null byte).
    _printf("Total Characters Printed: %d\n", len);

    return (0);
}

