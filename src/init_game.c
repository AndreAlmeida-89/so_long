/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 11:38:18 by andde-so          #+#    #+#             */
/*   Updated: 2023/05/20 12:10:49 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*load_image(t_vars *vars, char *path)
{
	return (mlx_xpm_file_to_image(
			vars->mlx,
			path,
			&vars->block_size,
			&vars->block_size));
}

void	init_game(t_vars *vars, char **map)
{
	vars->map = map;
	vars->mov_count = 0;
	vars->collec_count = count_number_of_chars(map, COLLECTABLE);
	vars->mlx = mlx_init();
	vars->block_size = 48;
	vars->x = (int)ft_strlen(*map) * vars->block_size;
	vars->y = str_tab_len(map) * vars->block_size;
	vars->win = mlx_new_window(
			vars->mlx,
			vars->x,
			vars->y,
			"so_long - 42 School - andde-so");
	vars->wall_img = load_image(vars, WALL_IMG);
	vars->player_img = load_image(vars, PLAYER_IMG);
	vars->exit_img = load_image(vars, EXIT_IMG);
	vars->collect_img = load_image(vars, COLLECT_IMG);
	vars->floor_img = load_image(vars, FLOOR_IMG);
	vars->player_pos = get_position(map, PLAYER);
}
