/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 22:18:19 by andde-so          #+#    #+#             */
/*   Updated: 2023/05/20 11:43:50 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	check_extention(const char *path, const char *extension)
{
	char	*dot;

	if (!path || ft_strlen(path) <= ft_strlen(extension) + 1)
		return (0);
	dot = ft_strrchr(path, '.');
	if (!dot)
		return (0);
	return (ft_strncmp(dot + 1, extension, ft_strlen(dot + 1)) == 0);
}

static char	*read_file(const char *path)
{
	int			fd;
	char		buffer[BUFF_SIZE + 1];
	char		*result;
	char		*temp;
	ssize_t		bytes;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		print_error("Path can not be open.", NULL);
	result = ft_strdup("");
	while (1)
	{
		bytes = read(fd, buffer, BUFF_SIZE);
		if (bytes == -1 && close(fd) == 0)
			print_error("File can not be read.", NULL);
		if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		temp = ft_strjoin(result, buffer);
		free(result);
		result = temp;
	}
	close(fd);
	return (result);
}

char	**parse_file(const char *path)
{
	char	**map;
	char	*file_content;

	if (!check_extention(path, "ber"))
		print_error("Invalid file extension.", NULL);
	file_content = read_file(path);
	map = ft_split(file_content, '\n');
	free(file_content);
	if (!*map)
		print_error("Empty file.", map);
	return (map);
}