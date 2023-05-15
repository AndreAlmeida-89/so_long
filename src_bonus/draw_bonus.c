/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 11:53:12 by andde-so          #+#    #+#             */
/*   Updated: 2023/05/15 16:33:14 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	*get_img(t_vars vars, t_content content)
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
	if (content == ENEMY)
		return (vars.enemy_img[vars.current_enemy_img]);
	return (0);
}

void	draw_block(t_vars vars, t_point p)
{
	mlx_put_image_to_window(
		vars.mlx,
		vars.win,
		get_img(vars, vars.map[p.x][p.y]),
		p.y * vars.block_size,
		p.x * vars.block_size);
}

static	void	draw_map(t_vars vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars.y)
	{
		j = 0;
		while (j < vars.x)
		{
			draw_block(
				vars,
				(t_point){i / vars.block_size, j / vars.block_size}
				);
			j += vars.block_size;
		}
		i += vars.block_size;
	}
}

static void	write_movements_count(t_vars *vars)
{
	char	*str;
	char	*str2;

	str = ft_itoa(vars->mov_count);
	str2 = ft_strjoin("Moves: ", str);
	mlx_string_put(
		vars->mlx,
		vars->win,
		5,
		10,
		0xFF0000,
		str2);
	free(str);
	free(str2);
}

int	loop_hook(t_vars *vars)
{
	static int	frame_count = 0;

	if (frame_count > SPRITE_FRAMES)
		frame_count = 0;
	vars->current_enemy_img = frame_count < (SPRITE_FRAMES / ENEMY_IMG_COUNT);
	draw_map(*vars);
	write_movements_count(vars);
	frame_count++;
	return (0);
}
