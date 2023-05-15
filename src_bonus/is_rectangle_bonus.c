/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rectangle_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 10:36:04 by andde-so          #+#    #+#             */
/*   Updated: 2023/05/14 23:40:39 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	is_rectangle(char **map)
{
	size_t	len;

	if (!*map)
		return (0);
	len = ft_strlen(*map);
	while (*++map)
		if (ft_strlen(*map) != len)
			return (0);
	return (1);
}
