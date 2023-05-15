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

SRC_B =		src_bonus/main_bonus.c 							\
			src_bonus/init_game_bonus.c						\
			src_bonus/draw_bonus.c							\
			src_bonus/handle_key_pressed_bonus.c			\
			src_bonus/print_error_bonus.c 					\
			src_bonus/parse_file_bonus.c					\
			src_bonus/str_tab_utils_bonus.c					\
			src_bonus/contains_only_bonus.c 				\
			src_bonus/has_valid_number_of_objects_bonus.c	\
			src_bonus/is_playable_bonus.c					\
			src_bonus/is_rectangle_bonus.c					\
			src_bonus/is_surrounded_by_walls_bonus.c		\
			src_bonus/handle_destroy_bonus.c				\
			src_bonus/is_valid_map_bonus.c					\
			src_bonus/get_position_bonus.c					\

NAME	=	so_long

OBJ		=	$(SRC:.c=.o)

OBJ_B	=	$(SRC_B:.c=.o)

CC		=	gcc

RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror

FM		=	-framework OpenGL -framework AppKit

LIBS	=	-Llibft -lft -Lmlx -lmlx

%.o:		%.c
			$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): 	$(OBJ)
			@make bonus -C libft
			@make -C mlx
			$(CC) $(OBJ) $(LIBS) $(FM) -o $(NAME)

all:		$(NAME)

clean:
			@make -C libft clean
			@make -C mlx clean
			$(RM) $(OBJ) $(OBJ_B)


fclean:		clean
			@make -C libft fclean
			$(RM) $(NAME)

re:			fclean all

run:	all
		./$(NAME) maps/map0.ber

bonus: 		$(OBJ_B)
			@make bonus -C libft
			@make -C mlx
			$(CC) $(OBJ_B) $(LIBS) $(FM) -o $(NAME)

.PHONY:		all clean fclean re
