/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 22:31:58 by abihe             #+#    #+#             */
/*   Updated: 2022/08/12 21:49:07 by abihe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	ft_right(t_map	*map)
{
	if (map->str[map->i][map->j + 1] != '1')
	{
		map->mv++;
		ft_printf("%d\n", map->mv);
		if (map->str[map->i][map->j + 1] == 'C')
			map->cl--;
		if (map->str[map->i][map->j + 1] == 'E' && map->cl == 0)
			exit (0);
		if (map->str[map->i][map->j + 1] != 'E')
		{
			map->str[map->i][map->j] = '0';
			map->str[map->i][map->j + 1] = 'P';
		}
	}
}

void	ft_left(t_map	*map)
{
	if (map->str[map->i][map->j - 1] != '1')
	{
		map->mv++;
		ft_printf("%d\n", map->mv);
		if (map->str[map->i][map->j - 1] == 'C')
			map->cl--;
		if (map->str[map->i][map->j - 1] == 'E' && map->cl == 0)
			exit (0);
		if (map->str[map->i][map->j - 1] != 'E')
		{
			map->str[map->i][map->j] = '0';
			map->str[map->i][map->j - 1] = 'P';
		}
	}
}

void	ft_down(t_map	*map)
{
	if (map->str[map->i + 1][map->j] != '1')
	{
		map->mv++;
		ft_printf("%d\n", map->mv);
		if (map->str[map->i + 1][map->j] == 'C')
			map->cl--;
		if (map->str[map->i + 1][map->j] == 'E' && map->cl == 0)
			exit (0);
		if (map->str[map->i + 1][map->j] != 'E')
		{
			map->str[map->i][map->j] = '0';
			map->str[map->i + 1][map->j] = 'P';
		}
	}
}

void	ft_upward(t_map	*map)
{
	if (map->str[map->i - 1][map->j] != '1')
	{
		map->mv++;
		ft_printf("%d\n", map->mv);
		if (map->str[map->i - 1][map->j] == 'C')
			map->cl--;
		if (map->str[map->i - 1][map->j] == 'E' && map->cl == 0)
			exit (0);
		if (map->str[map->i - 1][map->j] != 'E')
		{
			map->str[map->i][map->j] = '0';
			map->str[map->i - 1][map->j] = 'P';
		}
	}
}

int	key(int key_in, t_map *map)
{
	mlx_clear_window(map->mlx, map->win);
	if (key_in == 53)
		exit (0);
	if (key_in == 2 || key_in == 124)
		ft_right(map);
	if (key_in == 0 || key_in == 123)
		ft_left(map);
	if (key_in == 1 || key_in == 125)
		ft_down(map);
	if (key_in == 13 || key_in == 126)
		ft_upward(map);
	ft_put_img(map);
	return (1);
}
