#include "ft_printf.h"

void	ft_hexrecursive_pf(unsigned int number)
{
	unsigned int	remainder;
	char			save_rem;

	if (number == 0)
		return;
	ft_hexrecursive_pf(number / 16);
	remainder = number % 16;
	save_rem = (remainder + '0');
	if (remainder < 10)
		write(1, &save_rem, 1);
	else
	{
		save_rem = ((remainder - 10) + 'A');
		write(1, &save_rem, 1);
	}
}

void	ft_putmayushex_pf(va_list args)
{
	unsigned int	number;

	number = va_arg(args, unsigned int);
	ft_hexrecursive_pf(number);
}