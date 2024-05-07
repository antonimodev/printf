#include "libftprintf.h"

void	ft_putunsnbr_pf(va_list args)
{
	unsigned int	number;
	int				i;
	char			buffer[10];

	i = 0;
	number = va_arg(args, unsigned int);
	while (number > 0)
	{
		buffer[i] = (number % 10) + '0';
		i++;
		number = number / 10;
	}
	while (i > 0)
	{
		write(1, &buffer[i], 1);
		i--;
	}
}