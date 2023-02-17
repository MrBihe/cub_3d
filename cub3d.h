/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:08:36 by abihe             #+#    #+#             */
/*   Updated: 2023/02/16 20:05:02 by abihe            ###   ########.fr       */
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
void	ft_init(t_map *map);
void	set_map(char *file, t_map *map);
char	*ft_strrchr(const char *str, int ch);
void	check_filename(char *name);
void	ft_error(char *msg);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*get_texture(char *line);
void	inside_map(t_map *map);

#endif
