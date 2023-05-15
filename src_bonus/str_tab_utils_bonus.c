/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_tab_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 22:33:27 by andde-so          #+#    #+#             */
/*   Updated: 2023/05/14 23:41:01 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	str_tab_len(char **tab)
{
	int	len;

	len = 0;
	while (tab[len])
		len++;
	return (len);
}

size_t	count_chars(char *str, char c)
{
	size_t	number_of_chars;

	number_of_chars = 0;
	while (*str)
		if (*str++ == c)
			number_of_chars++;
	return (number_of_chars);
}

int	count_number_of_chars(char **map, char c)
{
	int	number_of_char;

	number_of_char = 0;
	while (*map)
		number_of_char += count_chars(*map++, c);
	return (number_of_char);
}

char	**cpy_tab(char **tab)
{
	int		i;
	int		j;
	char	**new_tab;

	i = str_tab_len(tab);
	new_tab = ft_calloc(i + 1, sizeof(char *));
	j = -1;
	while (++j < i)
		new_tab[j] = ft_strdup(tab[j]);
	return (new_tab);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
			free(tab[i++]);
		free(tab);
	}
}
