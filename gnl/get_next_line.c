/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 10:26:10 by andde-so          #+#    #+#             */
/*   Updated: 2022/11/05 15:15:04 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd, char *res)
{
	char	*buffer;
	int		bytes;
	char	*temp;

	if (!res)
		res = ft_strcalloc(1);
	buffer = ft_strcalloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (bytes && !ft_has_eol(buffer))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = 0;
		temp = ft_strjoin(res, buffer);
		free(res);
		res = temp;
	}
	free(buffer);
	return (res);
}

char	*get_first_line(char *buffer)
{
	char	*first_line;
	int		len;

	if (!*buffer)
		return (NULL);
	len = 0;
	while (buffer[len] && buffer[len] != '\n')
		len++;
	first_line = ft_strcalloc(len + 2);
	if (!first_line)
		return (NULL);
	len = 0;
	while (buffer[len] && buffer[len] != '\n')
	{
		first_line[len] = buffer[len];
		len++;
	}
	if (buffer[len] && buffer[len] == '\n')
		first_line[len++] = '\n';
	return (first_line);
}

char	*get_remain_after_eol(char *buffer)
{
	char	*remain;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	remain = ft_strcalloc((ft_strlen(buffer) - i + 1));
	j = 0;
	while (buffer[i++])
		remain[j++] = buffer[i];
	free(buffer);
	return (remain);
}

char	*get_next_line(int fd)
{
	char			*res;
	static char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	line = read_file(fd, line);
	if (!line)
		return (NULL);
	res = get_first_line(line);
	line = get_remain_after_eol(line);
	return (res);
}
