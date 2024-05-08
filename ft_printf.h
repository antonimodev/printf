#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <string.h>

int 	ft_printf(char const *format, ...);
void    ft_putchar_pf(va_list args);
void	ft_putstr_pf(va_list args);
void	ft_putptr_pf(va_list args);
void	ft_putnbr_pf(va_list args);
void	ft_putunsnbr_pf(va_list args);
void	ft_putminushex_pf(va_list args);
void	ft_putmayushex_pf(va_list args);
void	ft_aux_pf(char const *format, int *i, va_list args, int *count);

#endif