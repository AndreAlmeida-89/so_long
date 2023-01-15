SRC =		main.c 			\
			print_error.c 	\
			read_file.c		\
			str_tab_utils.c	\
			contains_only.c \
			has_valid_number_of_objects.c \
			is_playable.c \
			is_rectangle.c \
			is_surrounded_by_walls.c \
			is_valid_map.c \


NAME = so_long_main

OBJ	=	$(SRC:.c=.o)

CC		=	gcc

RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): 	$(OBJ)
			$(CC) $(OBJ) -Llibft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all:		$(NAME)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
