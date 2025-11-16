/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:26:23 by omaly             #+#    #+#             */
/*   Updated: 2025/11/16 22:19:29 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	parse_map(t_vertex **scene, t_map map)
{
	char	*line;
	int		row;

	row = 0;
	line = get_next_line(map.fd);
	while (line != NULL)
	{
		if (parse_line(scene, line, row, map.cols) != 0)
		{
			free(line);
			return (1);
		}
		free(line);
		row++;
		line = get_next_line(map.fd);
	}
	if (row != map.rows)
		return (2);
	return (0);
}
