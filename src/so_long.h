/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 21:44:16 by andde-so          #+#    #+#             */
/*   Updated: 2023/01/21 15:56:03 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "libft/libft.h"
#include "mlx/mlx.h"
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/fcntl.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
} t_event;

typedef enum
{
	WALL = '1',
	EMPTY = '0',
	PLAYER = 'P',
	COLLECTABLE = 'C',
	EXIT = 'E',
	MARK = 'X'
} t_content;

typedef struct s_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_data;

typedef struct s_vars
{
	void *mlx;
	void *win;
} t_vars;

typedef struct s_point
{
	int x;
	int y;
} t_point;

typedef struct s_block
{
	t_content content;
	t_point position;
	int is_showing_player;
} t_block;

typedef struct s_map
{
	int collectable_count;
	int width;
	int height;
	int mov_count;
	t_block **blocks;
} t_map;

int print_error(char *str);
char **read_file(const char *path);
int str_tab_len(char **tab);
size_t count_chars(char *str, char c);
int count_number_of_chars(char **map, char c);
char **cpy_tab(char **tab);
int is_valid_map(char **map);
int contains_only(char **map, const t_content *content);
int has_valid_number_of_objects(char **map);
int is_playable(char **map);
int is_rectangle(char **map);
int is_surrounded_by_walls(char **map);
int is_valid_map(char **map);

#endif
