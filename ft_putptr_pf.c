#include "libftprintf.h"

void	ft_putptr_pf(va_list args)
{
	void	*ptr;
	
	ptr = va_arg(args, void *);
	write(1, ptr, 1);
}