/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:36:55 by andde-so          #+#    #+#             */
/*   Updated: 2023/05/15 12:22:15 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	char	**map;
	t_vars	vars;

	if (argc != 2)
		return (1);
	map = parse_file(argv[1]);
	if (!*map)
		return (1);
	if (is_valid_map(map) == 0)
		return (1);
	init_game(&vars, map);
	mlx_loop_hook(vars.mlx, loop_hook, &vars);
	mlx_key_hook(vars.win, handle_key_pressed, &vars);
	mlx_hook(vars.win, ON_DESTROY, 1L << 0, handle_destroy, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
