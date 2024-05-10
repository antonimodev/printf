/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putminushex_pf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:15:09 by antonimo          #+#    #+#             */
/*   Updated: 2024/05/10 12:57:06 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexrecursive_pf(int number)
{
	int				remainder;
	char			save_rem;
	int				count;

	count = 0;
	if (number == 0)
		return (0);
	count += ft_hexrecursive_pf(number / 16);
	remainder = number % 16;
	save_rem = (remainder + '0');
	if (remainder < 10)
	{
		write(1, &save_rem, 1);
		count++;
	}
	else
	{
		save_rem = ((remainder - 10) + 'a');
		write(1, &save_rem, 1);
		count++;
	}
	return (count);
}

int	ft_putminushex_pf(va_list args)
{
	int	number;
	int	count;

	number = va_arg(args, int);
	count = ft_hexrecursive_pf(number);
	return (count);
}

/*En la función ft_hexrecursive_pf hacemos
remainder - 10 por que al sumarle 'a',
si tenemos el numero 10, el ASCII de 'a' + 10
sería 'k', y nosotros debemos representarlo en base
16, es decir, hasta la 'f'.

- ALTERNATIVA A ESTO: en lugar de - 10 y sumarle 'a'
podriamos simplemente sumarle 87, que en el ASCII es
'a' - 10.*/