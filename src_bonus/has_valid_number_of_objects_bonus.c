/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_valid_number_of_objects_bonus.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 10:37:53 by andde-so          #+#    #+#             */
/*   Updated: 2023/05/14 23:40:30 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	has_valid_number_of_objects(char **map)
{
	if (count_number_of_chars(map, EXIT) != 1)
		return (print_error("There should be one exit.", map));
	if (count_number_of_chars(map, PLAYER) != 1)
		return (print_error("There should be one player.", map));
	if (count_number_of_chars(map, COLLECTABLE) < 1)
		return (print_error("There should be at least one collectible.", map));
	return (1);
}
