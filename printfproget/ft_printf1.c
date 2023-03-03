/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiondo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:17:27 by fbiondo           #+#    #+#             */
/*   Updated: 2023/02/06 14:22:52 by fbiondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

int	ft_p_puutnbr(char c, unsigned long long nb)
{
	int				a;
	char			*base;
	static int		written;

	written = 0;
	a = nb % 16;
	nb = nb / 16;
	if (c == 'p')
	{
		c = 'b';
		write(1, "0x", 2);
	}
	if (nb > 0)
		ft_p_puutnbr(c, nb);
	base = "0123456789abcdef";
	written += write(1, &base[a], 1);
	return (written);
}

int	ft_x_puutnbr(char c, unsigned int nb)
{
	int				a;
	char			*base;
	static int		written;

	written = 0;
	a = nb % 16;
	nb = nb / 16;
	if (nb > 0)
		ft_x_puutnbr(c, nb);
	if (c == 'x')
		base = "0123456789abcdef";
	if (c == 'X')
		base = "0123456789ABCDEF";
	written += write(1, &base[a], 1);
	return (written);
}

int	ft_u_puutnbr(unsigned int n)
{
	unsigned int	a;
	static int		written;

	written = 0;
	a = n % 10;
	n = n / 10;
	if (n > 0)
		ft_u_puutnbr(n);
	a += 48;
	written += write(1, &a, 1);
	return (written);
}
