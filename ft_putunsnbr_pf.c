/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsnbr_pf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:15:40 by antonimo          #+#    #+#             */
/*   Updated: 2024/05/09 16:00:54 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsnbr_pf(va_list args)
{
	unsigned int	number;
	int				i;
	int				count;
	char			buffer[10];

	number = va_arg(args, unsigned int);
	i = 0;
	count = 0;
	if (number == 0)
	{
		count++;
		write(1, "0", 1);
	}
	while (number > 0)
	{
		buffer[i++] = (number % 10) + '0';
		number = number / 10;
	}
	while (i > 0)
	{
		i--;
		count++;
		write(1, &buffer[i], 1);
	}
	return (count);
}
