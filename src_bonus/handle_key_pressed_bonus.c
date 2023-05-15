/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_pressed_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:30:33 by andde-so          #+#    #+#             */
/*   Updated: 2023/05/15 16:30:55 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	move_from_to(t_vars *vars, t_point a, t_point b)
{
	static t_content	last_content = EMPTY;
	t_content			temp;

	if (b.x < str_tab_len(vars->map)
		&& b.y < (int)ft_strlen(*(vars->map))
		&& vars->map[b.x][b.y] != WALL
		&& ++(vars->mov_count))
	{
		if (((vars->map[b.x][b.y] == EXIT
				&& vars->collec_count == 0)
			|| (vars->map[b.x][b.y] == ENEMY)) &&
			vars->mov_count++)
			handle_destroy(vars);
		if (vars->map[b.x][b.y] == COLLECTABLE
			&& vars->collec_count--)
			vars->map[b.x][b.y] = EMPTY;
		temp = vars->map[b.x][b.y];
		vars->map[a.x][a.y] = last_content;
		vars->map[b.x][b.y] = PLAYER;
		last_content = temp;
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
