/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:08:36 by abihe             #+#    #+#             */
/*   Updated: 2023/02/22 17:31:47 by abihe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_3D_H
# define CUB_3D_H

# define BUFFER_SIZE 1

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct	s_map
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		f;
	int		c;
	int		elem;
	int		nb_line;
	int		flag;
	char	**l_map;
	char	player;
	int		player_x;
	int		player_y;
}	t_map;
//gnl
char	*get_next_line(int fd);
char	*ft_get_line(int fd, char *str);
int		ft_strchr(char *str, int c);
char	*ft_strjoin(char *str1, char *str2);
int		ft_strlen(char *str);
char	*ft_strdup(char *s1);
//pars
char	**ft_split(const char *s, char c);
char	*ft_strrchr(const char *str, int ch);
char	*skip_sp(char *line);
char	*get_texture(char *line);
char	*skip_sp(char *line);
int		ft_atoi(const char *str);
int		is_map_char(char c);
int		is_play(char pl);
int		if_all_empty(t_map *map);
int		if_textures_filled(t_map *map);
int		if_colors_filled(t_map *map);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		set_colors(char *line);
int		size_l(char *line, int j);
int		is_map(char *line);
void	ft_error(char *msg);
void	check_filename(char *name);
void	ft_init(t_map *map);
void	set_map(char *file, t_map *map);
void	p_pos(t_map *map, int i, int j);
void	fill_colors(char *line, t_map *map);
void	fill_textures(char *line, t_map *map);
void	all_ele_fil(t_map *map, char* line);
void	init_map(char *line, t_map *map);
void	inside_map(t_map *map);

#endif
