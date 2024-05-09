/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:15:16 by antonimo          #+#    #+#             */
/*   Updated: 2024/05/09 13:31:49 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_recursive_pf(int number, int *count)
{
	char	c;

	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		*count = 11;
		return ;
	}
	if (number < 0)
	{
		write(1, "-", 1);
		number = -number;
		(*count)++;
	}
	if (number > 9)
		ft_putnbr_recursive_pf(number / 10, count);
	c = (number % 10) + '0';
	write(1, &c, 1);
	(*count)++;
}

int	ft_putnbr_pf(va_list args)
{
	int		count;

	count = 0;
	ft_putnbr_recursive_pf(va_arg(args, int), &count);
	return (count);
}

/* Usamos un Buffer de 10 para almacenar los dígitos
en orden inverso y poder recorrerlos de delante
hacia detrás en el orden correcto.

- Además hacemos primero el decremento debido a que
nos encontramos en una posición adelantada */