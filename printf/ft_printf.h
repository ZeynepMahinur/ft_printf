#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h> 

int ft_putchar(char c);
int ft_putstr(char *str);
int ft_putnbr_base(int number, const char *base);
int ft_putnbr(int number);
int ft_percent(void);
int ft_printf(const char *f, ...);

#endif