/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarikan <zarikan@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 17:53:27 by zarikan           #+#    #+#             */
/*   Updated: 2025/06/21 17:53:28 by zarikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	formats(char c, va_list args)
{
	if (c == '%')
		c += ft_percent();
	else if (c == 'd' || c == 'i')
		c += ft_putnbr(va_arg(args, int));
	else if (c == 'X')
		c += ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF");
	else if (c == 'p')
		c += ft_putnbr_base(va_arg(args, int), "0x");
	else if (c == 'u')
		c += ft_putnbr_base(va_arg(args, int), "0123456789");
	else if (c == 'x')
		c += ft_putnbr_base(va_arg(args, int), "0123456789abcdef");
	else if (c == 'c')
		c += ft_putchar(va_arg(args, int));
	else if (c == 's')
		c += ft_putstr(va_arg(args, char *));
	return (0);
}

int	ft_printf(const char *f, ...)
{
	int		i;
	int		c;
	va_list	args;

	va_start (args, f);
	i = 0;
	c = 0;
	while (f[i])
	{
		if (f[i] == '%' && f[i + 1])
		{
			i++;
			c += formats(f[i], args);
		}
		else
			ft_putchar(f[i]);
		i++;
	}
	va_end(args);
	return (c);
}
