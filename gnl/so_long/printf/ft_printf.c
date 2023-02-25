/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:41:42 by abihe             #+#    #+#             */
/*   Updated: 2022/08/12 21:02:16 by abihe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_flag(char sign, va_list ap)
{
	int	i;

	i = 0;
	if (sign == '%')
		i += ft_putchar('%');
	else if (sign == 'c')
		i += ft_putchar(va_arg(ap, int));
	else if (sign == 's')
		i += ft_putstr(va_arg(ap, char *));
	else if (sign == 'd' || sign == 'i')
		i += ft_putnbr(va_arg(ap, int));
	else if (sign == 'u')
		i += ft_ptnbrunsigned(va_arg(ap, unsigned int));
	else if (sign == 'p')
	{
		i += ft_putstr("0x");
		i += ft_puthex(va_arg(ap, unsigned long), "0123456789abcdef");
	}
	else if (sign == 'x')
		i += ft_puthex(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (sign == 'X')
		i += ft_puthex(va_arg(ap, unsigned int), "0123456789ABCDEF");
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	p;
	int		l;

	i = 0;
	l = 0;
	va_start(p, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			l += ft_flag(str[i + 1], p);
			i++;
		}
		else
		{
			l += ft_putchar(str[i]);
		}
		i++;
	}
	va_end(p);
	return (l);
}
