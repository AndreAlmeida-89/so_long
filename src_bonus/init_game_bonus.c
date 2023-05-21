/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 11:38:18 by andde-so          #+#    #+#             */
/*   Updated: 2023/05/20 15:52:17 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	vars->player_img[0] = load_image(vars, PLAYER1_IMG);
	vars->player_img[1] = load_image(vars, PLAYER2_IMG);
	vars->collect_img[0] = load_image(vars, COLLECT1_IMG);
	vars->collect_img[1] = load_image(vars, COLLECT2_IMG);
	vars->enemy_img[0] = load_image(vars, ENEMY1_IMG);
	vars->enemy_img[1] = load_image(vars, ENEMY2_IMG);
	vars->exit_img[0] = load_image(vars, EXIT1_IMG);
	vars->exit_img[1] = load_image(vars, EXIT2_IMG);
	vars->floor_img = load_image(vars, FLOOR_IMG);
	vars->current_img_index = 0;
	vars->player_pos = get_position(map, PLAYER);
}
