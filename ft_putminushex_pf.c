/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putminushex_pf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:15:09 by antonimo          #+#    #+#             */
/*   Updated: 2024/05/09 16:02:58 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_hexrecursive_pf(unsigned int number)
{
	unsigned int	remainder;
	char			save_rem;

	if (number == 0)
		return ;
	ft_hexrecursive_pf(number / 16);
	remainder = number % 16;
	save_rem = (remainder + '0');
	if (remainder < 10)
		write(1, &save_rem, 1);
	else
	{
		save_rem = ((remainder - 10) + 'a');
		write(1, &save_rem, 1);
	}
}

void	ft_putminushex_pf(va_list args)
{
	unsigned int	number;

	number = va_arg(args, unsigned int);
	ft_hexrecursive_pf(number);
}

/*En la función ft_hexrecursive_pf hacemos
remainder - 10 por que al sumarle 'a',
si tenemos el numero 10, el ASCII de 'a' + 10
sería 'k', y nosotros debemos representarlo en base
16, es decir, hasta la 'f'.

- ALTERNATIVA A ESTO: en lugar de - 10 y sumarle 'a'
podriamos simplemente sumarle 87, que en el ASCII es
'a' - 10.*/