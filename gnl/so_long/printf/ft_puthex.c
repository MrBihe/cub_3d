/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:57:58 by abihe             #+#    #+#             */
/*   Updated: 2022/08/12 21:03:22 by abihe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_nb_hex(unsigned long nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		len++;
	while (nb)
	{
		nb = nb / 16;
		len++;
	}
	return (len);
}

int	ft_puthex(unsigned long n, char *str)
{
	int	i;

	i = ft_nb_hex(n);
	if (n > 15)
	{
		ft_puthex(n / 16, str);
		ft_puthex(n % 16, str);
	}
	else
		ft_putchar(str[n]);
	return (i);
}
