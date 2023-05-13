/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 22:18:19 by andde-so          #+#    #+#             */
/*   Updated: 2023/05/13 14:27:51 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_extention(const char *path, const char *extension)
{
	char	*dot;

	if (!path || ft_strlen(path) <= ft_strlen(extension) + 1)
		return (0);
	dot = ft_strrchr(path, '.');
	if (!dot)
		return (0);
	return (ft_strncmp(dot + 1, extension, ft_strlen(dot + 1)) == 0);
}

char	**parse_file(const char *path)
{
	char	**map;
	char	buffer[BUFF_SIZE];
	int		fd;

	if (!check_extention(path, "ber"))
		print_error("Invalid file extension.", NULL);
	fd = open(path, O_RDONLY);
	if (fd < 0 || read(fd, buffer, BUFF_SIZE) < 0)
		print_error("File can not be read.", NULL);
	map = ft_split(buffer, '\n');
	if (!*map)
		print_error("Empty file.", map);
	close(fd);
	return (map);
}
