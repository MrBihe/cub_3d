/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:08:29 by abihe             #+#    #+#             */
/*   Updated: 2023/02/15 19:16:39 by abihe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"
#include<stdio.h>


char *no_space(char *str)
{
	int j = 0;
	int i = 0;
 	while (str[i])
	{
		if (str[i] != ' ')
		{
			str[j] = str[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return str;
}

void	ft_error(char *msg)
{
	printf("Error\n%s\n", msg);
	exit(1);
}

void	ft_init(t_map *map)
{
	map->north = NULL;
	map->south = NULL;
	map->west = NULL;
	map->east = NULL;
	map->l_map = NULL;
	map->f = 0;
	map->c = 0;
	map->flag = -1;
	map->nb_line = 0;
}

int	is_map(char *line)
{
	int    i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == '1')
		return (1);
	return (0);
}

void	init_map(char *line, t_map *map)
{
	int	i;

	i = 0;
	if (is_map(line) || line[0] == '1')
	{
		if (map->flag == -1)
			map->flag = 0;
	}
	else if (!map->flag)
		map->flag = 1;
	else if ((is_map(line) || line[0] == '1') && map->flag)
	{
		if(line)
		{
			map->l_map[i] = line;
			free(line);
		}
		ft_error("empty world");
	}
}

void	inside_map(t_map *map)
{
	int	i;
	int j;
	int	p;
	
	i  = 0;
	p = -1;
	while(map->l_map[i])
	{
		j = 0;
		while(map->l_map[i][j])
		{
			if(map->l_map[i][j] != '1')
			{
				if(map->l_map[i][j] == 'N' || map->l_map[i][j] == 'S' || map->l_map[i][j] == 'E' || map->l_map[i][j] == 'W')
				{
					p = 0; 
					map->player_x = i;
					map->player_y = j;
					map->player = map->l_map[i][j];
					printf("i am in line [%d] and len [%d] and value ==> %c \n", map->player_x, map->player_y, map->player);
				}
				
			}
			j++;
		}
			
		i++;
	}
}


int	set_colors(char *line)
{
	char	**rgb;
	int		r;
	int		g;
	int		b;

	rgb = ft_split(line, ',');
	if(!rgb || !rgb[1] || !rgb[2])
		ft_error("Colors does not set!");
	r = atoi(rgb[0]);
	g = atoi(rgb[1]);
	b = atoi(rgb[2]);
	if((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
		ft_error("Colors does not set!");
	return(r << 16 | g << 8 | b);
}


char *get_texture(char *line)
{
	char	*result;
	char	*tmp;
	
	tmp = no_space(line);
	printf("[%s]\n", tmp);
	result = strdup(tmp + 2);
	printf("==>[%s]\n", result);
	if(access(result, R_OK))
		ft_error("Something!");
	return (result);
}

void check_textures(t_map *map, char *line ,int fd)
{
	int i = 0;
	while(line)
	{
	
	char *str;
	str = strdup(line);
	if (ft_strncmp("NO", str, 2) == 0)
		map->north = get_texture(line);
	if (ft_strncmp("SO", line, 2) == 0)
		map->south = get_texture(line);
	if (ft_strncmp("WE", line, 2) == 0)
		map->west = get_texture(line);
	if (ft_strncmp("EA", line, 2) == 0)
		map->east = get_texture(line);
	// if (line[0] == 'F')
	// 	map->f = set_colors(line);
	// if (line[0] == 'C')
	// 	map->c = set_colors(line);
	// if (line[0] == '1' && (!map->north || !map->south || !map->west || !map->east || !map->f || !map->c))
	// 	ft_error("Ssomething wrong with previous elements");
	// if (line[0] == '1' || is_map(line))
	// {
	// 	map->l_map[i] = strdup(line);
	// 	printf("line[] : %s\n", map->l_map[i]);
	// 	i++;
	// }
	free(line);
	line = get_next_line(fd);
	}
	map->l_map[i] = NULL;
}

void	set_map(char *file, t_map *map)
{
	int		i;
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	if(fd < 0)
		ft_error("File not found!");
	line = get_next_line(fd);
	i = 0;
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
	close(fd);
	fd = open(file, O_RDONLY);
		line = get_next_line(fd);
	check_textures(map, line, fd);
}

