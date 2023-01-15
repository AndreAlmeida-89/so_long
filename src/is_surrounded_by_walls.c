/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_surrounded_by_walls.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 10:33:39 by andde-so          #+#    #+#             */
/*   Updated: 2023/01/15 10:33:57 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int is_surrounded_by_walls(char **map)
{
	int i;
	int line_count;

	line_count = str_tab_len(map);
	i = 0;
	while (i < line_count)
	{
		if (i == 0 || i == line_count)
		{
			if (count_chars(map[i], '1') != ft_strlen(map[i]))
				return (0);
		}
		else if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}
