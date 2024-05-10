/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_pf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:13:36 by antonimo          #+#    #+#             */
/*   Updated: 2024/05/10 15:38:39 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_aux_pf(char const *format, int *i, va_list args)
{
	int	count;

	count = 0;
	if (format[*i] == 'c')
		count = ft_putchar_pf(args);
	else if (format[*i] == 's')
		count = ft_putstr_pf(args);
	else if (format[*i] == 'p')
		count = ft_putptr_pf(args);
	else if (format[*i] == 'd' || format[*i] == 'i')
		count = ft_putnbr_pf(args);
	else if (format[*i] == 'u')
		count = ft_putunsnbr_pf(args);
	else if (format[*i] == 'x' || format[*i] == 'X')
		count = ft_hex_pf(args, format[*i], &count);
	else if (format[*i] == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (count);
}
