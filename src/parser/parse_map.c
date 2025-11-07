/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:26:23 by omaly             #+#    #+#             */
/*   Updated: 2025/11/07 13:10:16 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

CHAR_SPACE;

int parse_line(t_fdf *fdf, const char *line)
{
	char **tokens = ft_split(line, ' ');
	if (!tokens)
		return 1;
	int i;
	i = 0;
	while (tokens[i] != NULL)
	{

	}

}

int line_count(char **line)
{
	int count;
	count = 0;
	if (!line)
	{
		return 0;
	}
	int i = 0;
	while (!line)
}

int parse_map(t_fdf *fdf)
{
	char *line;
	line = get_next_line(fdf->map->fd);
	while (line != NULL)
	{
		if (parse_line(fdf->scene, line) != 0)
			return 1;
		line = get_next_line(fdf->map->fd);
	}
	return 0;
}
