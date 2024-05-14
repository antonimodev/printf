/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:15:24 by antonimo          #+#    #+#             */
/*   Updated: 2024/05/14 16:20:04 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexptr_pf(unsigned long long number)
{
	char	str[25];
	char	*base_character;
	int		i;
	int		count;

	base_character = "0123456789abcdef";
	i = 0;
	count = 0;
	if (number == 0)
	{
		write(1, "0", 1);
		return (++count);
	}
	while (number != 0)
	{
		str[i] = base_character[number % 16];
		number = number / 16;
		i++;
	}
	while (i--)
	{
		write(1, &str[i], 1);
		count++;
	}
	return (count);
}

int	ft_putptr_pf(va_list args)
{
	void	*ptr;
	int		count;

	count = 2;
	ptr = va_arg(args, void *);
	write(1, "0x", 2);
	count += ft_hexptr_pf((unsigned long long) ptr);
	return (count);
}

/* Usamos unsigned long long para representar correctamente
la cantidad de números de la dirección de memoria en un
sistema de 64 bits. */