/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:38:04 by abihe             #+#    #+#             */
/*   Updated: 2023/02/21 18:27:53 by abihe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

char	*get_texture(char *line)
{
	char	*result;
	char	**sp;

	sp = ft_split(line, ' ');
	if (!sp || !sp[1] || sp[2])
		ft_error("something wrong with texture");
	result = ft_strdup(sp[1]);
	if (access(result, R_OK))
		ft_error("404! in texture file!");
	return (result);
}

void	fill_textures(char *line, t_map *map)
{
	if (ft_strncmp("NO ", line, 3) == 0)
	{
		map->north = get_texture(line);
		map->elem++;
	}
	if (ft_strncmp("SO ", line, 3) == 0)
	{
		map->south = get_texture(line);
		map->elem++;
	}
	if (ft_strncmp("WE ", line, 3) == 0)
	{
		map->west = get_texture(line);
		map->elem++;
	}
	if (ft_strncmp("EA ", line, 3) == 0)
	{
		map->east = get_texture(line);
		map->elem++;
	}
}

void	fill_colors(char *line, t_map *map)
{
	if (ft_strncmp("F ", line, 2) == 0)
	{
		map->f = set_colors(line);
		map->elem++;
	}
	if (ft_strncmp("C ", line, 2) == 0)
	{
		map->c = set_colors(line);
		map->elem++;
	}
}

void	init_map(char *line, t_map *map)
{
	static int	i;

	if (i < map->nb_line)
	{
		map->l_map[i] = ft_strdup(line);
		i++;
	}
	if (i == map->nb_line)
		map->l_map[i] = NULL;
}

void	all_ele_fil(t_map *map, char *line)
{
	if (line[0] == ' ' && !if_all_empty(map) && !map->l_map[0])
		line = skip_sp(line);
	if (!line[0])
		return ;
	if (!if_textures_filled(map))
		fill_textures(line, map);
	if (!if_colors_filled(map))
		fill_colors(line, map);
	
	else if (if_all_empty(map))
	{
		if (!line[0])
			return ;
		else if (!is_map_char(line[0]))
			ft_error("Wrong element inside map!");
		init_map(line, map);
	}
}
