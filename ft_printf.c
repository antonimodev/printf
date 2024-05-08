#include "ft_printf.h"

int ft_printf(char const *format, ...)
{
    int i;
    int count = 0;
    va_list args;
    va_start(args, format);

    i = 0;
    if (format == NULL)
        return (-1);
    while (format[i] != '\0')
    {
        if (format[i] == '%')
        {
            i++;
            ft_aux_pf(format, &i, args, &count);
        }
        else
        {
            write(1, &format[i], 1);
            count++;
        }
        i++;
    }
    va_end(args);
    return (count);
}

int main()
{
    int ret1 = ft_printf("Character: %c\n", 'A');
    int ret2 = printf("Character: %c\n", 'A');
    printf("-----------------------\n");
}

/*	cspdiuxX%
 * Character
 * String
 * Pointer
 * Decimal number
 * Integer
 * Decimal unsigned number
 * Hex minus
 * Hex mayus
 * Percentage symbol (%)
 */