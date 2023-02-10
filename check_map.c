/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:08:29 by abihe             #+#    #+#             */
/*   Updated: 2023/02/10 19:22:18 by abihe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"
#include<stdio.h>

void	set_map(char *file, t_map *map)
{
	int	i;

	map = malloc(sizeof(t_map));
	map->map_fd = open(file, O_RDONLY);
	map->line = get_next_line(map->map_fd);
	map->nb_line = 0;
	i = 0;
	if(!map->line)
	{
		printf("Error : Empty file!\n");
		exit(1);
	}
	while(map->line)
	{
		map->nb_line++;
		free(map->line);
		map->line= get_next_line(map->map_fd);
	}
	map->l_map = malloc(sizeof(char *) * map->nb_line);
	if(!map->l_map)
		exit(0);
	close(map->map_fd);
	open(file, O_RDONLY);
	while(i < map->nb_line)
	{
		map->l_map[i] = get_next_line(map->map_fd);
		printf("==> %s <==\n", map->l_map[i]);
		i++;
	}
}
int main(int argc, char **argv)
{
	t_map *map;
	set_map(argv[1], map);
	return (0);
}