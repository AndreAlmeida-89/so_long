/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 22:19:19 by andde-so          #+#    #+#             */
/*   Updated: 2023/05/14 23:40:55 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	print_error(char *str, char **map)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(str, 2);
	free_tab(map);
	exit(1);
}
