/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:47:39 by abihe             #+#    #+#             */
/*   Updated: 2023/02/16 23:51:16 by abihe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
	(void)argc;
	t_map *map;

	map = malloc(sizeof(t_map));
	check_filename(argv[1]);
	ft_init(map);
	set_map(argv[1], map);
	if (map)
	{
		printf("NO=%s\n", map->north);
		printf("SO=%s\n", map->south);
		printf("EA=%s\n", map->east);
		printf("WE=%s\n", map->west);
		printf("F=%d\n", map->f);
		printf("C=%d\n", map->c);
		for(int i = 0;map->l_map[i];i++)
			printf("map=%s\n", map->l_map[i]);
	}
	inside_map(map);
	return (0);
}