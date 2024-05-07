#include "libftprintf.h"

void	ft_putnbr_pf(va_list args)
{
	int	number;
	int	i;
	char buffer[10];

	number = va_arg(args, int);
	i = 0;
	if (number == 0)
		write(1, '0', 1);
	if (number < 0)
	{
		number = -number;
		buffer[i] = '-';
		i++;
	}
	while (number > 0)
	{
		buffer[i] = (number % 10) + '0';
		number = number / 10;
		i++;
	}
	while (i != 0)
	{
		write(1, &buffer[i], 1);
		i--;
	}
}


/* Usamos un Buffer de 10 para almacenar los dígitos
en orden inverso y poder recorrerlos de delante
hacia detrás en el orden correcto */