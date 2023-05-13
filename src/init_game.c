/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 11:38:18 by andde-so          #+#    #+#             */
/*   Updated: 2023/05/13 11:46:03 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_vars *vars, char **map)
{
	vars->map = map;
	vars->mov_count = 0;
	vars->collec_count = count_number_of_chars(map, COLLECTABLE);
	vars->mlx = mlx_init();
	vars->block_size = 48;
	vars->x = (int)ft_strlen(*map) * vars->block_size;
	vars->y = str_tab_len(map) * vars->block_size;
	vars->win = mlx_new_window(vars->mlx, vars->x, vars->y,
			"so_long - 42 School - andde-so");
	vars->wall_img = mlx_xpm_file_to_image(vars->mlx, WALL_IMG,
			&vars->block_size, &vars->block_size);
	vars->player_img = mlx_xpm_file_to_image(vars->mlx, PLAYER_IMG,
			&vars->block_size, &vars->block_size);
	vars->exit_img = mlx_xpm_file_to_image(vars->mlx, EXIT_IMG,
			&vars->block_size, &vars->block_size);
	vars->collect_img = mlx_xpm_file_to_image(vars->mlx, COLLECT_IMG,
			&vars->block_size, &vars->block_size);
	vars->floor_img = mlx_xpm_file_to_image(vars->mlx, FLOOR_IMG,
			&vars->block_size, &vars->block_size);
}