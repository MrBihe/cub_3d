/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 11:42:51 by abihe             #+#    #+#             */
/*   Updated: 2022/08/12 23:05:51 by abihe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	ft_checkelement(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->cl = 0;
	map->exit = 0;
	map->pla = 0;
	while (i < map->col)
	{
		j = 0;
		while (map->str[i][j])
		{
			if (map->str[i][j] == 'C')
				map->cl++;
			else if (map->str[i][j] == 'E')
				map->exit++;
			else if (map->str[i][j] == 'P')
				map->pla++;
			j++;
		}
		i++;
	}
	if (map->exit == 0 || map->cl == 0 || map->pla != 1)
		ft_error("Error : The map must contain 'E' & 'C' & 'P'");
	return (0);
}

void	ft_checkmap(t_map *map)
{
	int	i;

	i = 0;
	map->mv = 0;
	while (map->str[0][i])
		if (map->str[0][i++] != '1')
			ft_error("Error : The first wall not valid");
	i = 1;
	while (i < map->col - 1)
	{
		if (map->str[i][0] != '1' || map->str[i][map->row - 1] != '1')
			ft_error("Error : The midle wall not valid");
		i++;
	}
	i = 0;
	while (map->str[map->col - 1][i])
		if (map->str[map->col -1][i++] != '1')
			ft_error("Error : The last wall not valid");
	ft_checkelement(map);
	ft_foreign(map);
}

void	ft_read_map(char *file, t_map *map)
{
	map->fd = open(file, O_RDONLY);
	map->line = get_next_line(map->fd);
	if (!map->line)
		ft_error("Error : Something wrong with the map file!");
	map->row = ft_strlen(map->line);
	while (map->line)
	{
		map->col++;
		free(map->line);
		map->line = get_next_line(map->fd);
	}
	map->str = malloc(sizeof(char *) * map->col);
	if (!map->str)
		exit(0);
	close(map->fd);
	map->fd = open(file, O_RDONLY);
	map->index = 0;
	while (map->index < map->col)
	{
		map->str[map->index] = get_next_line(map->fd);
		if (ft_strlen(map->str[0]) != ft_strlen(map->str[map->index]))
			ft_error("Error : The walls it's not perfectly built");
		map->index++;
	}
}

int	ft_close(t_map *map)
{
	mlx_destroy_window(map->mlx, map->win);
	exit (0);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		ft_error("You must enter 2 Arguments!");
	if (ft_strchr(argv[1], '.'))
	{
		if (ft_strncmp(ft_strrchr(argv[1], '.'), ".ber", 4))
			ft_error("Error : Something wrong with the map file!");
	}
	else
		ft_error("Error : Something wrong with the map file!");
	map.col = 0;
	ft_read_map(argv[1], &map);
	ft_checkmap(&map);
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, map.row * 50, map.col * 50, "hero");
	ft_put_img(&map);
	mlx_key_hook(map.win, key, &map);
	mlx_hook(map.win, 17, 0, ft_close, &map);
	mlx_loop(map.mlx);
	return (0);
}
