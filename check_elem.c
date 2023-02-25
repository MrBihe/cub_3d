/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:07:17 by abihe             #+#    #+#             */
/*   Updated: 2023/02/19 17:18:27 by abihe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	if_textures_filled(t_map *map)
{
	if (map->north && map->south && map->east && map->west)
		return (1);
	return (0);
}

int	if_colors_filled(t_map *map)
{
	if (map->c && map->f)
		return (1);
	return (0);
}

int	if_all_empty(t_map *map)
{
	if (map->north && map->south && map->east && map->west && map->f && map->c)
		return (1);
	return (0);
}

int	is_play(char pl)
{
	if (pl == 'N' || pl == 'S' || pl == 'E' || pl == 'W')
		return (1);
	return (0);
}

int	is_map_char(char c)
{
	if (is_play(c) || c == ' ' || c == '0' || c == '1')
		return (1);
	return (0);
}
