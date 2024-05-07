#include "libftprintf.h"

void	ft_putstr_pf(va_list args)
{
	int		i;
	char	*str;

	i = 0;
	str = va_arg(args, char *);
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}