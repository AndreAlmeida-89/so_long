/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_valid_number_of_objects.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 10:37:53 by andde-so          #+#    #+#             */
/*   Updated: 2023/02/18 18:11:08 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	has_valid_number_of_objects(char **map)
{
	if (count_number_of_chars(map, EXIT) != 1)
		return (print_error("There should be one exit."));
	if (count_number_of_chars(map, PLAYER) != 1)
		return (print_error("There should be one player."));
	if (count_number_of_chars(map, COLLECTABLE) < 1)
		return (print_error("There should be at least one collectible."));
	if (count_number_of_chars(map, EMPTY) < 1)
		return (print_error("There should be at least one empty space"));
	return (1);
}
