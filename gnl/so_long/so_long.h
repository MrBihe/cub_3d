/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 11:42:28 by abihe             #+#    #+#             */
/*   Updated: 2022/08/12 23:22:23 by abihe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 1

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdarg.h>

typedef struct s_map
{
	int		fd;
	int		col;
	int		row;
	int		exit;
	int		cl;
	int		pla;
	int		width;
	int		height;
	int		x;
	int		y;
	int		i;
	int		j;
	int		mv;
	int		index;
	char	**str;
	char	*line;
	void	*mlx;
	void	*img;
	void	*win;
}	t_map;

// utils
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *str, int ch);
void	ft_error(char *str);
// GNL
char	*get_next_line(int fd);
char	*ft_get_line(int fd, char *str);
int		ft_strchr(char *str, int c);
char	*ft_strjoin(char *str1, char *str2);
int		ft_strlen(char *str);
char	*ft_strdup(char *s1);
//SL
void	ft_read_map(char *file, t_map *map);
void	ft_side_wall(t_map *map, char *file);
void	ft_foreign(t_map *map);
void	ft_images(t_map *map, char *path);
void	ft_put_img(t_map *map);
int		key(int key_in, t_map *map);
//Printf
int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_puthex(unsigned long n, char *str);
int		ft_putnbr(int n);
int		ft_ptnbrunsigned(unsigned int n);

#endif