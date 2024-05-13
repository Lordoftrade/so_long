NAME = so_long

SRCS =	get_next_line.c get_next_line_utils.c main.c checking.c checking2.c map.c working_map.c moving.c free.c

INCLUDE = so_long.h

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLX = -framework OpenGL -framework AppKit -lmlx

all : $(NAME)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

$(NAME) : $(OBJS) $(INCLUDE)
	$(CC) $(CFLAGS) $(OBJS) -I./include $(MLX) -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: clean fclean re all
