#include "ft_printf.h"

void	ft_hexrecursive_pf(unsigned long long number)
{
	unsigned int	remainder;
	char			save_remainder;

	if (number == 0)
		return;
	ft_hexrecursive_pf(number / 16);
	remainder = number % 16;
	save_remainder = remainder + '0';
	if (number < 10)
		write(1, &save_remainder, 1);
	else
	{
		save_remainder = (remainder - 10) + 'a';
		write(1, &save_remainder, 1);
	}
}

void	ft_putptr_pf(va_list args)
{
	void	*ptr;
	
	ptr = va_arg(args, void *);
	write(1, "0x", 2);
	ft_hexrecursive_pf((unsigned long long)ptr);
}

/*Usamos unsigned long long para representar correctamente
la cantidad de números de la dirección de memoria en un
sistema de 64 bits.*/