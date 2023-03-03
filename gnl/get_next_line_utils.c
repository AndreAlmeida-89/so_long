/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 10:26:06 by andde-so          #+#    #+#             */
/*   Updated: 2022/11/05 14:55:40 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;

	res = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	j = 0;
	i = 0;
	while (s1 && s1[i])
	{
		res[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2 && s2[i])
	{
		res[j] = s2[i];
		i++;
		j++;
	}
	res[j] = '\0';
	return (res);
}

char	*ft_strcalloc(size_t len)
{
	char	*str;
	size_t	i;

	str = malloc(len * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len * sizeof(char))
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

int	ft_has_eol(char *str)
{
	while (str && *str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}
