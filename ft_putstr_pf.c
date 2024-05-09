/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:15:32 by antonimo          #+#    #+#             */
/*   Updated: 2024/05/09 11:15:35 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_pf(va_list args)
{
	int		i;
	char	*str;

	i = 0;
	str = va_arg(args, char *);
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}
