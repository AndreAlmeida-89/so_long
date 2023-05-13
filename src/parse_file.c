/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 22:18:19 by andde-so          #+#    #+#             */
/*   Updated: 2023/05/13 15:17:49 by andde-so         ###   ########.fr       */
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

static	size_t	get_file_size(const char *path)
{
	size_t	size;
	char	buff;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-1);
	size = 0;
	while (read(fd, &buff, sizeof(char)))
		size++;
	close(fd);
	return (size);
}

char	**parse_file(const char *path)
{
	char	**map;
	char	*buffer;
	int		fd;
	size_t	file_size;

	if (!check_extention(path, "ber"))
		print_error("Invalid file extension.", NULL);
	file_size = get_file_size(path);
	fd = open(path, O_RDONLY);
	if (fd < 0 || file_size < 0)
	{
		print_error("File can not be read.", NULL);
		close(fd);
	}
	buffer = ft_calloc(file_size, sizeof(char));
	read(fd, buffer, file_size);
	map = ft_split(buffer, '\n');
	if (!*map)
		print_error("Empty file.", map);
	close(fd);
	free(buffer);
	return (map);
}
