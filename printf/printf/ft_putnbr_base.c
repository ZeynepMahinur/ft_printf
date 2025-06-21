/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarikan <zarikan@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 17:13:09 by zarikan           #+#    #+#             */
/*   Updated: 2025/06/21 17:13:26 by zarikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(int number, const char *base)
{
	unsigned long	nb;
	unsigned long	len;

	nb = number;
	len = 0;
	while (base[len])
		len++;
	if (nb >= len)
	{
		ft_putnbr_base(nb / len, base);
	}
	write (1, &base[nb % len], 1);
	return (nb);
}
