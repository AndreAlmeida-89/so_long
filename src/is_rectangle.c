/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rectangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 10:36:04 by andde-so          #+#    #+#             */
/*   Updated: 2023/01/15 10:36:35 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int is_rectangle(char **map)
{
	size_t len;

	if (!*map)
		return (0);
	len = strlen(*map);
	while (*++map)
		if (strlen(*map) != len)
			return (0);
	return (1);
}
