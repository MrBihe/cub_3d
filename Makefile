NAME = cub3D

SRCS = check_map.c gnl/get_next_line.c gnl/get_next_line_utils.c main.c check_filename.c ft_split.c ft_strdup.c

CC = gcc

CFLAGS = -Wall -Wextra -Werror  -o $(NAME) 

all : $(NAME)
$(NAME) : $(SRCS)
	@$(CC) $(CFLAGS) $(SRCS)

clean :
	@rm -f $(NAME)

fclean : clean
	@rm -f $(NAME)

re : fclean all