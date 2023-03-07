SRC =		src/main.c 							\
			src/print_error.c 					\
			src/parse_file.c					\
			src/str_tab_utils.c					\
			src/contains_only.c 				\
			src/has_valid_number_of_objects.c	\
			src/is_playable.c					\
			src/is_rectangle.c					\
			src/is_surrounded_by_walls.c		\
			src/is_valid_map.c					\
			get_next_line/get_next_line.c		\
			get_next_line/get_next_line_utils.c	\

NAME	=	so_long

OBJ		=	$(SRC:.c=.o)

CC		=	gcc

RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror

%.o:		%.c
			$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): 	$(OBJ)
			@make -C libft
			$(CC) $(OBJ) -Llibft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all:		$(NAME)

clean:
			@make -C libft clean
			$(RM) $(OBJ)

fclean:		clean
			@make -C libft fclean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
