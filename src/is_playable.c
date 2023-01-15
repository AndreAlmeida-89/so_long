/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_playable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 10:38:37 by andde-so          #+#    #+#             */
/*   Updated: 2023/01/15 10:38:54 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void mark_reachable_path(char **map, int row, int col)
{
	if (map[row][col] == 'X' || map[row][col] == '1')
		return ;

	map[row][col] = 'X';

	mark_reachable_path(map, row, col + 1);
	mark_reachable_path(map, row, col - 1);
	mark_reachable_path(map, row + 1, col);
	mark_reachable_path(map, row - 1, col);
}

int is_playable(char **map)
{
	char **cpy;
	int row;
	int col;
	int found_player;
	int is_playable;

	found_player = 0;
	cpy = cpy_tab(map);
	row = 0;
	col = 0;
	while (cpy[row] && !found_player)
	{
		col = 0;
		while (cpy[row][col] && !found_player)
		{
			if (cpy[row][col] == 'P' && found_player++)
				break;
			col++;
		}
		row++;
	}
	mark_reachable_path(cpy, row - 1, col - 1);
	is_playable = contains_only(cpy, "01X");
	while (*cpy)
		free(*cpy++);
	return (is_playable);
}
