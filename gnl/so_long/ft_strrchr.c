/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:40:09 by abihe             #+#    #+#             */
/*   Updated: 2022/07/05 12:11:09 by abihe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

char	*ft_strrchr(const char *str, int ch)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i != 0)
	{
		if (str[i] == (char) ch)
			return ((char *)&str[i]);
		i--;
	}
	if (str[i] == (char) ch)
		return ((char *)&str[i]);
	return (0);
}
