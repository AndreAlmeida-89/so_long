/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:36:55 by andde-so          #+#    #+#             */
/*   Updated: 2023/02/18 19:48:48 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*get_img(t_vars vars, t_content content)
{
	if (content == PLAYER)
		return (vars.player_img);
	if (content == EXIT)
		return (vars.exit_img);
	if (content == COLLECTABLE)
		return (vars.collect_img);
	if (content == WALL)
		return (vars.wall_img);
	if (content == EMPTY)
		return (vars.floor_img);
	return (NULL);
}

void	draw_map(t_vars vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars.y)
	{
		j = 0;
		while (j < vars.x)
		{
			mlx_put_image_to_window(
				vars.mlx, vars.win,
				get_img(vars,
					vars.map[i / vars.block_size][j / vars.block_size]),
				j, i);
			j += vars.block_size;
		}
		i += vars.block_size;
	}
}

t_point	get_position(char **map, char c)
{
	int	row;
	int	col;
	int	has_found;

	row = 0;
	has_found = 0;
	while (map[row] && !has_found)
	{
		col = 0;
		while (map[row][col] && !has_found)
		{
			if (map[row][col] == c && has_found++)
				break ;
			col++;
		}
		row++;
	}
	return ((t_point){row - 1, col - 1});
}

int	handle_destroy(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	ft_putendl_fd("Game closed", 1);
	exit(0);
}

void	move_from_to(t_vars *vars, t_point a, t_point b)
{
	if (vars->map[b.x][b.y] == EXIT && vars->collec_count == 0)
	{
		vars->mov_count++;
		printf("Movments: %d\n", vars->mov_count);
		handle_destroy(vars);
		return ;
	}
	if (b.x < str_tab_len(vars->map)
		&& b.y < (int)ft_strlen(*(vars->map))
		&& vars->map[b.x][b.y] != WALL
		&& vars->map[b.x][b.y] != EXIT)
	{
		if (vars->map[b.x][b.y] == COLLECTABLE)
			vars->collec_count--;
		vars->map[a.x][a.y] = EMPTY;
		vars->map[b.x][b.y] = PLAYER;
		vars->mov_count++;
		printf("Movments: %d\n", vars->mov_count);
		draw_map(*vars);
	}
}

int	handle_key_pressed(int keycode, t_vars *vars)
{
	t_point	p;

	p = get_position(vars->map, PLAYER);
	if (keycode == W_KEY || keycode == UP_KEY)
		move_from_to(vars, p, (t_point){p.x - 1, p.y});
	else if (keycode == A_KEY || keycode == LEFT_KEY)
		move_from_to(vars, p, (t_point){p.x, p.y - 1});
	else if (keycode == S_KEY || keycode == DOWN_KEY)
		move_from_to(vars, p, (t_point){p.x + 1, p.y});
	else if (keycode == D_KEY || keycode == RIGHT_KEY)
		move_from_to(vars, p, (t_point){p.x, p.y + 1});
	else if (keycode == ESC_KEY)
		handle_destroy(vars);
	else
		printf("Keycode: %d\n", keycode);
	return (0);
}

void	load_images(t_vars *vars)
{
	vars->wall_img = mlx_xpm_file_to_image(
			vars->mlx,
			WALL_IMG,
			&vars->block_size,
			&vars->block_size);
	vars->player_img = mlx_xpm_file_to_image(
			vars->mlx,
			PLAYER_IMG,
			&vars->block_size,
			&vars->block_size);
	vars->exit_img = mlx_xpm_file_to_image(
			vars->mlx,
			EXIT_IMG,
			&vars->block_size,
			&vars->block_size);
	vars->collect_img = mlx_xpm_file_to_image(
			vars->mlx,
			COLLECT_IMG,
			&vars->block_size,
			&vars->block_size);
	vars->floor_img = mlx_xpm_file_to_image(
			vars->mlx,
			FLOOR_IMG,
			&vars->block_size,
			&vars->block_size);
}

int	main(int argc, char **argv)
{
	char	**map;
	t_vars	vars;

	if (argc != 2)
		return (1);
	map = read_file(argv[1]);
	if (!*map)
		return (1);
	printf("MAP IS VALID: %d\n", is_valid_map(map));
	vars.map = map;
	vars.mov_count = 0;
	vars.collec_count = count_number_of_chars(map, COLLECTABLE);
	vars.mlx = mlx_init();
	vars.block_size = 48;
	vars.x = ft_strlen(*map) * vars.block_size;
	vars.y = str_tab_len(map) * vars.block_size;
	vars.win = mlx_new_window(vars.mlx, vars.x, vars.y, "Hello world!");
	load_images(&vars);
	draw_map(vars);
	mlx_key_hook(vars.win, handle_key_pressed, &vars);
	mlx_hook(vars.win, ON_DESTROY, 1L << 0, handle_destroy, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
