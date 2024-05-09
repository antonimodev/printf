/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:14:01 by antonimo          #+#    #+#             */
/*   Updated: 2024/05/09 11:14:20 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	count = 0;
	va_start(args, format);
	i = 0;
	if (format == NULL)
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			ft_aux_pf(format, &i, args, &count);
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

/* int	main(void)
{
	int ret1, ret2;
	// For character
	ret1 = ft_printf("Character: %c\n", 'A');
	ret2 = printf("Character: %c\n", 'A');
	printf("-----------------------\n");
	// For string
	ret1 = ft_printf("String: %s\n", "Hello, World!");
	ret2 = printf("String: %s\n", "Hello, World!");
	printf("-----------------------\n");
	// For decimal (base 10)
	ret1 = ft_printf("Decimal: %d\n", 12345);
	ret2 = printf("Decimal: %d\n", 12345);
	printf("-----------------------\n");
	// For integer
	ret1 = ft_printf("Integer: %i\n", -12345);
	ret2 = printf("Integer: %i\n", -12345);
	printf("-----------------------\n");
} */

/*	cspdiuxX%
 * Character
 * String
 * Pointer
 * Decimal number
 * Integer
 * Decimal unsigned number
 * Hex minus
 * Hex mayus
 * Percentage symbol (%)
 */