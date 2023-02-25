/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:08:29 by abihe             #+#    #+#             */
/*   Updated: 2023/02/25 17:14:50 by abihe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"
#include<stdio.h>

void	ft_init(t_map *map)
{
	map->north = NULL;
	map->south = NULL;
	map->west = NULL;
	map->east = NULL;
	map->l_map = NULL;
	map->f = 0;
	map->elem = 0;
	map->c = 0;
	map->flag = -1;
	map->nb_line = 0;
}

void	inside_map(t_map *map)
{
	int	i;
	int j;
	
	i  = 0;
			printf("========>%d\n", map->nb_line);
	while(map->l_map[i])
	{
		j = 0;
		while(map->l_map[i][j])
		{
			if ((map->l_map[i][j] == '0' || is_play(map->l_map[i][j])) 
				&& (i == 0 || j == 0 || map->l_map[i][j + 1] == '\0'|| map->l_map[i + 1] == NULL
				|| map->l_map[i][j + 1] == ' ' || map->l_map[i][j - 1] == ' '
				|| size_l(map->l_map[i - 1], j) || size_l(map->l_map[i + 1], j)
				|| map->l_map[i + 1][j] == ' ' || map->l_map[i - 1][j] == ' '))
				{
					printf("i am in line [%d] and len [%d] and value ==> %c \n", i, j, map->l_map[i][j]);
					ft_error("map fucked!");
				}
			if (!is_map_char(map->l_map[i][j]))
			{
				printf("i am in line [%d] and len [%d] and value ==> %c \n", i, j, map->l_map[i][j]);	
				ft_error("There is a foreign charachter");
			}
			if(is_play(map->l_map[i][j]))
				p_pos(map, i, j);
			j++;
		}
		i++;
	}
}

void	check_textures(t_map *map, char *line ,int fd)
{
	while(line)
	{
		all_ele_fil(map, line);
		free(line);
		line = get_next_line(fd);
	}
		printf("[%d] elements\n", map->elem);
}

void	colors_check(char *line)
{
	int	i;
	int	c;
	
	i = 0;
	c = 0;
	while (line[i])
	{
		if (line[i] == ',' && line[i + 1] == ',')
			ft_error("To much commas");
		else if (line[i] == ',')
			c++;
		i++;
	}
	if(c != 2 || line[i - 1] == ',')
		ft_error("Color");
}

int	set_colors(char *line)
{
	char	**rgb;
	char	**color;
	int		r;
	int		g;
	int		b;

	colors_check(line);
	color = ft_split(line, ' ');
	if(color[2] || !color[1])
	ft_error("ilias");
	rgb = ft_split(color[1], ',');
	
	if(!rgb || !rgb[1] || !rgb[2])
		ft_error("Color does not set correctly!");
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	printf("rgb[0] >[%s]<\n",rgb[0]);
	printf("r >[%d]<\n",r);
	printf("g >[%d]<\n",g);
	printf("b >[%d]<\n",b);
	if((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
		ft_error("Color value are wrong!");
	return(r << 16 | g << 8 | b);
}

void	set_map(char *file, t_map *map)
{
	// int		i;
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	if(fd < 0)
		ft_error("File not found!");
	line = get_next_line(fd);
	// i = 0;
	if(!line)
		ft_error("Empty file!");
	while(line)
	{
		if (is_map(line) || line[0] == '1')
		{
			if (map->flag == -1)
				map->flag = 0;
			map->nb_line++;
		}
		else if (!map->flag)
			map->flag = 1;
		if ((is_map(line) || line[0] == '1') && map->flag)
		{
			if(line)
				free(line);
			ft_error("empty world");
		}
		line = get_next_line(fd);
	}
	map->l_map = malloc(sizeof(char *) * (map->nb_line + 1));
	map->l_map[0] = NULL;
	close(fd);
	fd = open(file, O_RDONLY);
		line = get_next_line(fd);
	check_textures(map, line, fd);
	if (map->nb_line == 0)
		ft_error("map not set yet!");
}

