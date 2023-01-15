/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contains_only.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 10:32:00 by andde-so          #+#    #+#             */
/*   Updated: 2023/01/15 10:32:38 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int contains_only(char **map, const char *str)
{
	int i;

	while (*map)
	{
		i = 0;
		while (*(*map + i))
			if (ft_strchr(str, *(*map + i++)) == NULL)
				return (0);
		map++;
	}
	return (1);
}
