/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_pf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:24:45 by antonimo          #+#    #+#             */
/*   Updated: 2024/05/10 15:05:45 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_checkhex_pf(char x_or_X)
{
	char	*base_character;

	if (x_or_X == 'X')
		base_character = "0123456789ABCDEF";
	else
		base_character = "0123456789abcdef";
	return (base_character);
}

int	ft_hex_pf(va_list arg, char x_or_X, int *count)
{
	char			str[25];
	char			*base_character;
	int				i;
	unsigned int	number;

	base_character = ft_checkhex_pf(x_or_X);
	i = 0;
	number = va_arg(arg, int);
	if (number == 0)
	{
		write(1, "0", 1);
		(*count)++;
	}
	while (number != 0)
	{
		str[i] = base_character [number % 16];
		number = number / 16;
		i++;
	}
	while (i--)
	{
		write(1, &str[i], 1);
		(*count)++;
	}
	return (*count);
}
