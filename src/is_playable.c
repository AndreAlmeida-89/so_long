/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_playable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 10:38:37 by andde-so          #+#    #+#             */
/*   Updated: 2023/05/14 18:01:08 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mark_reachable_path(char **map, int row, int col)
{
	if (map[row][col] == MARK || map[row][col] == WALL)
		return ;
	map[row][col] = MARK;
	mark_reachable_path(map, row, col + 1);
	mark_reachable_path(map, row, col - 1);
	mark_reachable_path(map, row + 1, col);
	mark_reachable_path(map, row - 1, col);
}

int	is_playable(char **map)
{
	char	**map_copy;
	int		is_playable;
	t_point	player_position;

	map_copy = cpy_tab(map);
	player_position = get_position(map_copy, PLAYER);
	mark_reachable_path(
		map_copy,
		player_position.x,
		player_position.y);
	is_playable = contains_only(map_copy, (t_content *)"01X");
	free_tab(map_copy);
	return (is_playable);
}
