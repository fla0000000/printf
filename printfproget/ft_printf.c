/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiondo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:20:24 by fbiondo           #+#    #+#             */
/*   Updated: 2023/02/06 14:20:47 by fbiondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

int	ft_choose(va_list *lst, char c)
{
	int	written;

	written = 0;
	if (c == '%')
	{	
		write(1, "%", 1);
		written++;
	}
	else if (c == 'c')
		written += ft_puutchar(va_arg(*lst, int));
	else if (c == 's')
		written += ft_puutstr(va_arg(*lst, char *));
	else if (c == 'd' || c == 'i')
		ft_puutnbr(va_arg(*lst, int), &written);
	else if (c == 'u')
		written += ft_u_puutnbr(va_arg(*lst, unsigned int));
	else if (c == 'x' || c == 'X')
		written += ft_x_puutnbr(c, va_arg(*lst, unsigned int));
	else if (c == 'p')
	{
		written += 2;
		written += ft_p_puutnbr(c, va_arg(*lst, unsigned long long));
	}
	return (written);
}

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		j;
	int		count;

	va_start(list, format);
	j = 0;
	count = 0;
	while (format[j])
	{
		if (format[j] == '%')
		{
			j++;
			count += ft_choose(&list, format[j]);
			j++;
		}
		else
		{
			count += write(1, &format[j], 1);
			j++;
		}
	}
	va_end (list);
	return (count);
}
