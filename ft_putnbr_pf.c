/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:15:16 by antonimo          #+#    #+#             */
/*   Updated: 2024/05/14 14:42:18 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_pf(int number, int *count)
{
	int		digit;

	if (number == -2147483648)
	{
		if (ft_putstr_pf("-2147483648") == -1)
			return (-1);
		(*count) = (*count) + 11;
		return (*count);
	}
	if (number < 0)
	{
		if (ft_putchar_pf('-') == -1)
			return (-1);
		number = -number;
		(*count)++;
	}
	if (number > 9)
		ft_putnbr_pf(number / 10, count);
	digit = (number % 10) + '0';
	if (ft_putchar_pf(digit) == -1)
		return (-1);
	(*count)++;
	return (*count);
}

/* Usamos un Buffer de 10 para almacenar los dígitos
en orden inverso y poder recorrerlos de delante
hacia detrás en el orden correcto.

- Además hacemos primero el decremento debido a que
nos encontramos en una posición adelantada */