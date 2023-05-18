/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 22:18:19 by andde-so          #+#    #+#             */
/*   Updated: 2023/05/18 08:43:34 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


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

static void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	if (ptr == NULL)
		return (malloc(size));
	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(size);
	if (new_ptr == NULL)
		return (NULL);
	ft_memcpy(new_ptr, ptr, size);
	free(ptr);
	return (new_ptr);
}

static char	*read_file(const char *path)
{
	int		fd;
	char	buffer[BUFF_SIZE];
	char	*result;
	size_t	result_len;
	ssize_t	bytes_read;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		print_error("File can not be read.", NULL);
	}
	result = NULL;
	result_len = 0;
	while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0)
	{
		result = ft_realloc(result, result_len + bytes_read + 1);
		ft_memcpy(result + result_len, buffer, bytes_read);
		result_len += bytes_read;
	}
	if (result != NULL)
		result[result_len] = '\0';
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
	if (!map)
		print_error("File has no content.", NULL);
	if (!*map)
		print_error("Empty file.", map);
	return (map);
}