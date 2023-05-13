/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 10:39:35 by andde-so          #+#    #+#             */
/*   Updated: 2023/05/13 15:33:39 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_map(char **map)
{
	if (!is_rectangle(map))
		return (print_error("The map must be rectangular.", map));
	if (!contains_only(map, (t_content *)"01PCE"))
		return (print_error("The map has invalid characters", map));
	if (!has_valid_number_of_objects(map))
		return (print_error("The map has invalid number of objects.", map));
	if (!is_surrounded_by_walls(map))
		return (print_error("The map must be surrounded by walls.", map));
	if (!is_playable(map))
		return (print_error("There's no valid path in the map.", map));
	return (1);
}
