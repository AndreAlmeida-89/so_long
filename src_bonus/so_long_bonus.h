/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 21:44:16 by andde-so          #+#    #+#             */
/*   Updated: 2023/05/20 12:30:00 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <unistd.h>
# include <sys/fcntl.h>
# include <stdlib.h>

# define PLAYER_IMG "img/player1.xpm"
# define WALL_IMG "img/wall.xpm"
# define EXIT_IMG "img/exit.xpm"
# define COLLECT_IMG "img/collect.xpm"
# define FLOOR_IMG "img/floor.xpm"
# define ENEMY1_IMG "img/enemy1.xpm"
# define ENEMY2_IMG "img/enemy2.xpm"
# define ENEMY_IMG_COUNT 2
# define SPRITE_FRAMES 16
# define BUFF_SIZE 1024

typedef enum e_event
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
}				t_event;

typedef enum e_key
{
	W_KEY = 13,
	A_KEY = 0,
	S_KEY = 1,
	D_KEY = 2,
	UP_KEY = 126,
	LEFT_KEY = 123,
	DOWN_KEY = 125,
	RIGHT_KEY = 124,
	ESC_KEY = 53
}			t_key;

typedef enum e_content
{
	WALL = '1',
	EMPTY = '0',
	PLAYER = 'P',
	COLLECTABLE = 'C',
	EXIT = 'E',
	ENEMY = '2',
	MARK = 'X'
}				t_content;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	char	**map;
	void	*wall_img;
	void	*player_img;
	void	*exit_img;
	void	*collect_img;
	void	*floor_img;
	void	*enemy_img[ENEMY_IMG_COUNT];
	int		current_enemy_img;
	int		collec_count;
	int		mov_count;
	int		x;
	int		y;
	int		block_size;
	t_point	player_pos;
}	t_vars;

int		print_error(char *str, char **map);
char	**parse_file(const char *path);
int		str_tab_len(char **tab);
size_t	count_chars(char *str, char c);
int		count_number_of_chars(char **map, char c);
char	**cpy_tab(char **tab);
int		is_valid_map(char **map);
int		contains_only(char **map, const t_content *content);
int		has_valid_number_of_objects(char **map);
int		is_playable(char **map);
int		is_rectangle(char **map);
int		is_surrounded_by_walls(char **map);
int		is_valid_map(char **map);
int		handle_destroy(t_vars *vars);
void	free_tab(char **tab);
void	init_game(t_vars *vars, char **map);
int		handle_key_pressed(int keycode, t_vars *vars);
t_point	get_position(char **map, char c);
int		loop_hook(t_vars *vars);

#endif
