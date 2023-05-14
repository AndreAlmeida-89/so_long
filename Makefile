SRC =		src/main.c 							\
			src/init_game.c						\
			src/draw.c							\
			src/handle_key_pressed.c			\
			src/print_error.c 					\
			src/parse_file.c					\
			src/str_tab_utils.c					\
			src/contains_only.c 				\
			src/has_valid_number_of_objects.c	\
			src/is_playable.c					\
			src/is_rectangle.c					\
			src/is_surrounded_by_walls.c		\
			src/handle_destroy.c				\
			src/is_valid_map.c					\
			src/get_position.c					\

NAME	=	so_long

OBJ		=	$(SRC:.c=.o)

CC		=	gcc

RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror

%.o:		%.c
			$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): 	$(OBJ)
			@make bonus -C libft
			@make -C mlx
			$(CC) $(OBJ) -Llibft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all:		$(NAME)

clean:
			@make -C libft clean
			@make -C mlx clean
			$(RM) $(OBJ)

fclean:		clean
			@make -C libft fclean
			$(RM) $(NAME)

re:			fclean all

run:	all
		./$(NAME) maps/map0.ber

.PHONY:		all clean fclean re
