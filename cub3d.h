/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:08:36 by abihe             #+#    #+#             */
/*   Updated: 2023/02/10 22:45:25 by abihe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_3D_H
# define CUB_3D_H

# define BUFFER_SIZE 1

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

typedef struct	s_map
{
	int		map_fd;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		f;
	int		c;
	char	*line;
	int		nb_line;
	char	**l_map;
}	t_map;
//gnl
char	*get_next_line(int fd);
char	*ft_get_line(int fd, char *str);
int		ft_strchr(char *str, int c);
char	*ft_strjoin(char *str1, char *str2);
int		ft_strlen(char *str);
char	*ft_strdup(char *s1);
//pars
void	set_map(char *file, t_map *map);
void	check_filename(char *name);
void	ft_error(char *msg);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	get_var(t_map *map);

#endif
