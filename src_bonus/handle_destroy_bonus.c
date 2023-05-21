/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_destroy_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 10:07:12 by andde-so          #+#    #+#             */
/*   Updated: 2023/05/20 16:11:44 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	handle_destroy(t_vars *vars)
{
	int	i;

	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_image(vars->mlx, vars->floor_img);
	mlx_destroy_image(vars->mlx, vars->wall_img);
	i = 0;
	while (++i < IMG_COUNT)
	{
		mlx_destroy_image(vars->mlx, vars->exit_img[i]);
		mlx_destroy_image(vars->mlx, vars->enemy_img[i]);
		mlx_destroy_image(vars->mlx, vars->player_img[i]);
		mlx_destroy_image(vars->mlx, vars->collect_img[i]);
	}
	free_tab(vars->map);
	exit(0);
}
