/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 22:18:19 by andde-so          #+#    #+#             */
/*   Updated: 2023/05/13 11:17:56 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int file_size(const char *path)
// {
// 	char	buffer;
// 	int		fd;
// 	int		char_count;

// 	char_count = 0;
// 	fd = open(path, O_RDONLY);
// 	if (fd < 0)
// 		print_error("File can not be read.");
// 	while (read(fd, &buffer, sizeof(char)) > 0)
// 		char_count++;
// 	close(fd);
// 	return (char_count);
// }

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

// char **parse_file(const char *path)
// {
// 	char **map;
// 	char *buffer;
// 	int len;
// 	int fd;

// 	if (!check_extention(path, "ber"))
// 		print_error("Invalid file extension.");
// 	len = file_size(path);
// 	fd = open(path, O_RDONLY);
// 	buffer = ft_calloc(len + 1, sizeof(char));
// 	if (read(fd, buffer, len) < 0)
// 		return (NULL);
// 	map = ft_split(buffer, '\n');
// 	if (!*map)
// 		print_error("Empty file.");
// 	free(buffer);
// 	close(fd);
// 	return (map);
// }


char	**parse_file(const char *path)
{
	char	**map;
	char	buffer[BUFF_SIZE];
	char	*temp;
	int		fd;

	if (!check_extention(path, "ber"))
		print_error("Invalid file extension.", NULL);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		print_error("File can not be read.", NULL);
	while (1)
	{
		ft_bzero(buffer, sizeof(buffer));
		if (read(fd, buffer, sizeof(buffer)) <= 0)
			break ;
		temp = ft_strjoin(temp, buffer);
	}
	printf("STR:\n%s\n", temp);
	map = ft_split(temp, '\n');
	free(temp);
	if (!*map)
		print_error("Empty file.", map);
	close(fd);
	return (map);
}