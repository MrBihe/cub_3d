/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_images.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:19:31 by abihe             #+#    #+#             */
/*   Updated: 2022/08/12 23:00:50 by abihe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_foreign(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->col)
	{
		j = 0;
		while (map->str[i][j])
		{
			if (map->str[i][j] != '1' && map->str[i][j] != 'P'
				&& map->str[i][j] != 'E' && map->str[i][j] != 'C'
				&& map->str[i][j] != '0')
				ft_error("Error : The map contains a foreign character");
			j++;
		}
		i++;
	}
}

void	ft_images(t_map *map, char *path)
{
	map->img = mlx_xpm_file_to_image(map->mlx, path, &map->width, &map->height);
	mlx_put_image_to_window(map->mlx, map->win, map->img,
		map->x * 50, map->y * 50);
	mlx_destroy_image(map->mlx, map->img);
}

void	ft_put_img(t_map *map)
{
	map->y = 0;
	while (map->y < map->col)
	{
		map->x = 0;
		while (map->x < map->row)
		{
			if (map->str[map->y][map->x] == '1')
				ft_images(map, "./img/wall.xpm");
			if (map->str[map->y][map->x] == '0')
				ft_images(map, "./img/in.xpm");
			if (map->str[map->y][map->x] == 'C')
				ft_images(map, "./img/ms.xpm");
			if (map->str[map->y][map->x] == 'E')
				ft_images(map, "./img/do.xpm");
			if (map->str[map->y][map->x] == 'P')
			{
				ft_images(map, "./img/ker.xpm");
				map->j = map->x;
				map->i = map->y;
			}
			map->x++;
		}
		map->y ++;
	}
}
