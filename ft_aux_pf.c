#include "libftprintf.h"

void ft_aux_pf(char const *format, int *i, va_list args, int *count)
{
  if (format[*i] == 'c')
    ft_putchar_pf(args);
  else if (format[*i] == 's')
    ft_putstr_pf(args);
  else if (format[*i] == 'p')
    ft_putptr_pf(args);
  else if (format[*i] == 'd' || format[*i] == 'i')
    ft_putnbr_pf(args);
  else if (format[*i] == 'u')
    ft_putuns_pf(args);
  else if (format[*i] == 'x')
    ft_putminushex_pf(args);
  else if (format[*i] == 'X')
    ft_putmayushex_pf(args);
  else if (format[*i] == '%')
    write(1, '%', 1);
    (*count)++;
}
