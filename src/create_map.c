/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:30:04 by andde-so          #+#    #+#             */
/*   Updated: 2023/01/15 16:27:11 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


t_block create_block(char **tab, int row, int col)
{
	t_block	block;
	t_point pos;

	pos.x = col;
	pos.y = row;
	block.position = pos;
	block.content = tab[row][col];
	block.is_showing_player = block.content == PLAYER;
	return(block);
}

t_map	*create_map(char **tab)
{
	t_map *map;
	int		row;
	int		col;

	map = malloc(sizeof(map));
	map->height = str_tab_len(tab);
	map->width = ft_strlen(*tab);
	map->collectable_count = count_number_of_chars(tab, COLLECTABLE);
	map->mov_count = 0;
	map->blocks = malloc(sizeof(t_block) * map->height * map->width);
	row = 0;
	while (tab[row])
	{
		col = 0;
		while (tab[row][col])
		{
			map->blocks[row][col] = create_block(tab, row, col);
			col++;
		}
		row++;
	}
	return (map);
}
