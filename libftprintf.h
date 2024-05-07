#ifndef LIBFTPRINTF.H
# define LIBFTPRINTF.H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <string.h>

void	ft_putunsnbr_pf(va_list args);
void	ft_putstr_pf(va_list args);
void	ft_putnbr_pf(va_list args);
void    ft_putchar_pf(va_list args);
void    ft_aux_pf(char const *format, int *i, va_list args, int *count);

#endif