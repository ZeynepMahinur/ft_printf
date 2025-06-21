#include "ft_printf.h"

int    ft_printf(const char *f, ...)
{
    va_list args;
    va_start(args, f);
    int i;
    int c;

    i = 0;
    c = 0;
    while (f[i])
    {
        if (f[i] == '%')
        {
            i++;
            c += ft_percent();
            if (f[i] == 'd' || f[i] == 'i')
                c += ft_putnbr(va_arg(args, int));
            else if (f[i] == 'p')
                c += ft_putnbr_base(va_arg(args, int) "0x");
            else if (f[i] == 'c')
                c += ft_putchar(va_arg(args, int));
            else if (f[i] == 's')
                c += ft_putstr(va_arg(args, int));
        }
    }
    va_end(args);
    return (c);
}