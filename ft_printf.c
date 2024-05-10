/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:14:01 by antonimo          #+#    #+#             */
/*   Updated: 2024/05/10 15:53:00 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			count = count + ft_aux_pf(format, &i, args);
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
	int	num;

	int ret1, ret2;
	// For character
	ret1 = ft_printf("Character: %c\n", 'A');
	ret2 = printf("Character: %c\n", 'A');
	printf("ft_printf returned: %d, printf returned: %d\n", ret1, ret2);
	printf("-----------------------\n");
	// For string
	ret1 = ft_printf("String: %s\n", "Hello, World!");
	ret2 = printf("String: %s\n", "Hello, World!");
	printf("ft_printf returned: %d, printf returned: %d\n", ret1, ret2);
	printf("-----------------------\n");
	// For pointer
	num = 10;
	ret1 = ft_printf("Pointer: %p\n", &num);
	ret2 = printf("Pointer: %p\n", &num);
	printf("ft_printf returned: %d, printf returned: %d\n", ret1, ret2);
	printf("-----------------------\n");
	// For decimal (base 10)
	ret1 = ft_printf("Decimal: %d\n", 12345);
	ret2 = printf("Decimal: %d\n", 12345);
	printf("ft_printf returned: %d, printf returned: %d\n", ret1, ret2);
	printf("-----------------------\n");
	// For integer
	ret1 = ft_printf("Integer: %i\n", -12345);
	ret2 = printf("Integer: %i\n", -12345);
	printf("ft_printf returned: %d, printf returned: %d\n", ret1, ret2);
	printf("-----------------------\n");
	// For unsigned
	ret1 = ft_printf("Unsigned: %u\n", 12345);
	ret2 = printf("Unsigned: %u\n", 12345);
	printf("ft_printf returned: %d, printf returned: %d\n", ret1, ret2);
	printf("-----------------------\n");
	// For hexadecimal (lowercase)
	ret1 = ft_printf("Hexadecimal (lowercase): %x\n", -1);
	ret2 = printf("Hexadecimal (lowercase): %x\n", -1);
	printf("ft_printf returned: %d, printf returned: %d\n", ret1, ret2);
	printf("-----------------------\n");
	// For hexadecimal (uppercase)
	ret1 = ft_printf("Hexadecimal (uppercase): %X\n", 0x123abc);
	ret2 = printf("Hexadecimal (uppercase): %X\n", 0x123abc);
	printf("ft_printf returned: %d, printf returned: %d\n", ret1, ret2);
	printf("-----------------------\n");
	// For percent
	ret1 = ft_printf("Percent: %%\n");
	ret2 = printf("Percent: %%\n");
	printf("ft_printf returned: %d, printf returned: %d\n", ret1, ret2);
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