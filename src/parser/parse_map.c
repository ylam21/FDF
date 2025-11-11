/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:26:23 by omaly             #+#    #+#             */
/*   Updated: 2025/11/11 14:53:43 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	parse_map(t_vertex **scene, t_map map)
{
	char	*line;
	int		curr_row;

	curr_row = 0;
	line = get_next_line(map.fd);
	while (line != NULL)
	{
		if (parse_line(scene, line, curr_row, map.cols) != 0)
		{
			free(line);
			return (1);
		}
		free(line);
		curr_row++;
		line = get_next_line(map.fd);
	}
	if (curr_row != map.rows)
	{
		return (2);
	}
	return (0);
}
