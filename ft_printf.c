#include "libft.h"
#include <stdio.h>
#include <stdarg.h>

static char	ft_check(char *ptr, int pos)
{
	if (ptr[pos + 1] == 'c')
		return ('c');
	else if (ptr[pos + 1] == 's')
		return ('s');
	else if (ptr[pos + 1] == 'p')
		return ('p');
	else if (ptr[pos + 1] == 'd')
		return ('d');
	else if (ptr[pos + 1] == 'i')
		return ('i');
	else if (ptr[pos + 1] == 'u')
		return ('u');
	else if (ptr[pos + 1] == 'x')
		return ('x');
	else if (ptr[pos + 1] == 'X')
		return ('X');
	else if (ptr[pos + 1] == '%')
		return ('%');
	else
		return('e');
}
static int	ft_flag(char *ptr, int pos)
{
	if (ft_check(ptr, pos) != 'e')
		return (1);
	return (0);
}

int	ft_printf(char const *format, ...)
{
	int	i;
	va_list	args;
	va_start(args, format);

	i = 0;
	if (format == NULL)
		return (NULL);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			i++;
			if (format[i] == 'c')

		write(1, &format[i], 1);
		i++;
	}
	va_end(args);
}

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