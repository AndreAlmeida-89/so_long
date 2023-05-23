/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 22:18:19 by andde-so          #+#    #+#             */
/*   Updated: 2023/05/23 17:54:26 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_extention(const char *path, const char *extension)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(path);
	j = ft_strlen(extension);
	while (path[--i] && extension[--j])
		if (path[i] != extension[j])
			return (0);
	return (1);
}

void	clean_str(char **tab)
{
	while (*tab)
		*tab = ft_strtrim(*tab++, "\r");
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

	if (!check_extention(path, ".ber"))
		print_error("Invalid file extension.", NULL);
	file_content = read_file(path);
	map = ft_split(file_content, '\n');
	clean_str(map);
	free(file_content);
	if (!*map)
		print_error("Empty file.", map);
	return (map);
}
