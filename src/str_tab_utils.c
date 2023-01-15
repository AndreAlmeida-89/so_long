/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_tab_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 22:33:27 by andde-so          #+#    #+#             */
/*   Updated: 2023/01/13 22:34:35 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int str_tab_len(char **tab)
{
	int len;

	len = 0;
	while (*tab++)
		len++;
	return (len);
}

size_t count_chars(char *str, char c)
{
	size_t number_of_chars;

	number_of_chars = 0;
	while (*str)
		if (*str++ == c)
			number_of_chars++;
	return (number_of_chars);
}

int count_number_of_chars(char **map, char c)
{
	int number_of_char;

	number_of_char = 0;
	while (*map)
		number_of_char += count_chars(*map++, c);
	return (number_of_char);
}

char **cpy_tab(char **tab)
{
	char **cpy;
	size_t len;
	int i;

	len = str_tab_len(tab) * ft_strlen(*tab) * sizeof(char);
	cpy = malloc(len);
	if (!cpy)
		return (NULL);
	i = 0;
	while (tab[i])
	{
		cpy[i] = ft_strdup(tab[i]);
		i++;
	}
	return (cpy);
}
