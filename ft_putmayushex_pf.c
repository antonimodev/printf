/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmayushex_pf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:14:58 by antonimo          #+#    #+#             */
/*   Updated: 2024/05/09 16:12:32 by antonimo         ###   ########.fr       */
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
		save_rem = ((remainder - 10) + 'A');
		write(1, &save_rem, 1);
	}
}

void	ft_putmayushex_pf(va_list args)
{
	unsigned int	number;

	number = va_arg(args, unsigned int);
	ft_hexrecursive_pf(number);
}
