/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_map_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:10:49 by omaly             #+#    #+#             */
/*   Updated: 2025/11/07 13:23:51 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int is_space(char c)
{
	return (c == ' ');
}

int count_tokens(char *line)
{
	int count = 0;
	if (!line)
		return 0;
	int i = 0;
	while (line[i] != '\0')
	{
		while (is_space(line[i]))
			i++;
		if (ft_isalnum(line[i]))
			count++;
		while (ft_isalnum(line[i]))
			i++;
	}
	return count;
}

int calc_map_size(t_map *map)
{
	int size;
	size = 0;
	char *line = get_next_line(map->fd);
	while (line != NULL)
	{
		size = size + count_tokens(line);
		line = get_next_line(map->fd);
	}
	return size;
}
