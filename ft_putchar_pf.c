#include "ft_printf.h"

void    ft_putchar_pf(va_list args)
{
    char    c;

    c = (char)va_arg(args, int);
    write(1, &c, 1);
}