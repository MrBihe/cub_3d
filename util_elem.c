/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_elem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:14:31 by abihe             #+#    #+#             */
/*   Updated: 2023/02/19 18:24:32 by abihe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_map(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == '1')
		return (1);
	return (0);
}

void	p_pos(t_map *map, int i, int j)
{
	map->player_x = i;
	map->player_y = j;
	map->player = map->l_map[i][j];
	printf("i am in line [%d] and len [%d] and value ==> %c \n", map->player_x, map->player_y, map->player);
}

int	size_l(char *line, int j)
{
	if (j > ft_strlen(line) - 1)
		return (1);
	return (0);
}

char	*skip_sp(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ')
			return (line + i);
		i++;
	}
	return (line);
}
