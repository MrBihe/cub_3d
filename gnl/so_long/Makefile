# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abihe <abihe@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 16:38:47 by abihe             #+#    #+#              #
#    Updated: 2022/08/12 21:48:11 by abihe            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = ./so_long.c ./ft_error.c ./ft_strncmp.c ./ft_strrchr.c ./ft_images.c ./ft_move.c ./gnl/get_next_line.c ./gnl/get_next_line_utils.c ./printf/ft_putchar.c\
./printf/ft_printf.c ./printf/ft_ptnbrunsigned.c ./printf/ft_puthex.c ./printf/ft_putnbr.c ./printf/ft_putstr.c

CC = gcc

CFLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit -o $(NAME) 

all : $(NAME)
$(NAME) : $(SRCS)
	@$(CC) $(CFLAGS) $(SRCS)

clean :
	@rm -f $(NAME)

fclean : clean
	@rm -f $(NAME)

re : fclean all