/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_position_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:57:41 by andde-so          #+#    #+#             */
/*   Updated: 2023/05/14 23:40:20 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_point	get_position(char **map, char c)
{
	int	row;
	int	col;
	int	has_found;

	row = 0;
	col = 0;
	has_found = 0;
	while (map[row] && !has_found)
	{
		col = 0;
		while (map[row][col] && !has_found)
		{
			if (map[row][col] == c && has_found++)
				break ;
			col++;
		}
		row++;
	}
	return ((t_point){row - 1, col - 1});
}
