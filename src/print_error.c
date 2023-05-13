/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 22:19:19 by andde-so          #+#    #+#             */
/*   Updated: 2023/05/13 10:16:59 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	print_error(char *str, t_vars *vars)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(str, 2);
	return (handle_destroy(vars));
}
