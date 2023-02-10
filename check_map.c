/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:08:29 by abihe             #+#    #+#             */
/*   Updated: 2023/02/10 22:51:16 by abihe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"
#include<stdio.h>

void	ft_error(char *msg)
{
	printf("Error\n%s\n", msg);
	exit(1);
}

void	set_map(char *file, t_map *map)
{
	int	i;

	map->map_fd = open(file, O_RDONLY);
	if(map->map_fd < 0)
		ft_error("File not found!");
	map->line = get_next_line(map->map_fd);
	map->nb_line = 0;
	i = 0;
	if(!map->line)
		ft_error("Empty file!");
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

void	get_var(t_map *map)
{
	int i;

	i = 0;
	while(i <= map->nb_line)
	{
		if(ft_strncmp("NO", map->l_map[i], 2) == 0)
		{
			printf("%s\n", map->l_map[i]);
			// exit(1);
		}
		i++;
	}
}