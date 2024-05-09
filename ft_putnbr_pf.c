/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:15:16 by antonimo          #+#    #+#             */
/*   Updated: 2024/05/09 11:15:20 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_pf(va_list args)
{
	int		number;
	int		i;
	char	buffer[10];

	number = va_arg(args, int);
	i = 0;
	if (number == 0)
		write(1, "0", 1);
	if (number < 0)
	{
		number = -number;
		write(1, "-", 1);
	}
	while (number > 0)
	{
		buffer[i] = (number % 10) + '0';
		number = number / 10;
		i++;
	}
	while (i != 0)
	{
		i--;
		write(1, &buffer[i], 1);
	}
}

/* Usamos un Buffer de 10 para almacenar los dígitos
en orden inverso y poder recorrerlos de delante
hacia detrás en el orden correcto.

- Además hacemos primero el decremento debido a que
nos encontramos en una posición adelantada */