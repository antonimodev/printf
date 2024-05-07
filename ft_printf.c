#include "libftprintf.h"

int ft_printf(char const *format, ...)
{
    int i;
    int count = 0;
    va_list args;
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

int main()
{
    int ret1 = ft_printf("Character: %c\n", 'A');
    int ret2 = printf("Character: %c\n", 'A');
    printf("-----------------------\n");
    
    int ret3 = ft_printf("String: %s\n", "Hello, World!");
    int ret4 = printf("String: %s\n", "Hello, World!");
    printf("-----------------------\n");
    
    int ret5 = ft_printf("Pointer: %p\n", &ret1);
    int ret6 = printf("Pointer: %p\n", &ret1);
    printf("-----------------------\n");
    
    int ret7 = ft_printf("Decimal: %d\n", 123);
    int ret8 = printf("Decimal: %d\n", 123);
    printf("-----------------------\n");
    
    int ret9 = ft_printf("Integer: %i\n", 123);
    int ret10 = printf("Integer: %i\n", 123);
    printf("-----------------------\n");
    
    unsigned int u = 123;
    int ret11 = ft_printf("Unsigned decimal: %u\n", u);
    int ret12 = printf("Unsigned decimal: %u\n", u);
    printf("-----------------------\n");
    
    int ret13 = ft_printf("Hexadecimal (lowercase): %x\n", 123);
    int ret14 = printf("Hexadecimal (lowercase): %x\n", 123);
    printf("-----------------------\n");
    
    int ret15 = ft_printf("Hexadecimal (uppercase): %X\n", 123);
    int ret16 = printf("Hexadecimal (uppercase): %X\n", 123);
    printf("-----------------------\n");

    int ret15 = ft_printf("Hexadecimal (uppercase): %%\n");
    int ret16 = printf("Hexadecimal (uppercase): %%\n");
    printf("-----------------------\n");
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