/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsnbr_pf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:15:40 by antonimo          #+#    #+#             */
/*   Updated: 2024/05/09 11:15:47 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		i--;
		write(1, &buffer[i], 1);
	}
}
