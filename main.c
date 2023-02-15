/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:47:39 by abihe             #+#    #+#             */
/*   Updated: 2023/02/15 15:52:20 by abihe            ###   ########.fr       */
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
	inside_map(map);
	return (0);
}