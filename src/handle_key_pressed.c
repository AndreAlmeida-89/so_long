/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_pressed.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:30:33 by andde-so          #+#    #+#             */
/*   Updated: 2023/05/14 23:21:27 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_from_to(t_vars *vars, t_point a, t_point b)
{
	static int	exit_flag = 0;

	if (vars->map[b.x][b.y] == EXIT && vars->collec_count == 0)
		handle_destroy(vars);
	if (b.x < str_tab_len(vars->map)
		&& b.y < (int)ft_strlen(*(vars->map))
		&& vars->map[b.x][b.y] != WALL)
	{
		if (vars->map[b.x][b.y] == COLLECTABLE)
			vars->collec_count--;
		if (exit_flag && exit_flag--)
			vars->map[a.x][a.y] = EXIT;
		else
			vars->map[a.x][a.y] = EMPTY;
		if (vars->map[b.x][b.y] == EXIT)
			exit_flag++;
		vars->map[b.x][b.y] = PLAYER;
		vars->mov_count++;
		ft_putstr_fd("Movments: ", 1);
		ft_putnbr_fd(vars->mov_count, 1);
		ft_putstr_fd("\n", 1);
		draw_block(*vars, a);
		draw_block(*vars, b);
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
	return (0);
}
