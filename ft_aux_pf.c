/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_pf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:13:36 by antonimo          #+#    #+#             */
/*   Updated: 2024/05/09 11:32:33 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_aux_pf(char const *format, int *i, va_list args)
{
	if (format[*i] == 'c')
		ft_putchar_pf(args);
	else if (format[*i] == 's')
		ft_putstr_pf(args);
	else if (format[*i] == 'p')
		ft_putptr_pf(args);
	else if (format[*i] == 'd' || format[*i] == 'i')
		ft_putnbr_pf(args);
	else if (format[*i] == 'u')
		ft_putunsnbr_pf(args);
	else if (format[*i] == 'x')
		ft_putminushex_pf(args);
	else if (format[*i] == 'X')
		ft_putmayushex_pf(args);
	else if (format[*i] == '%')
		write(1, "%", 1);
}
