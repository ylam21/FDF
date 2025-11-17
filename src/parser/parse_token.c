/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:47:10 by omaly             #+#    #+#             */
/*   Updated: 2025/11/17 09:31:33 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	parse_null_token(t_vertex *vertex, int row, int col)
{
	if (vertex == NULL)
		return (1);
	vertex->x = col;
	vertex->y = row;
	vertex->z = 0;
	vertex->color = WHITE_COLOR;
	return (0);
}

int	parse_token(t_vertex *vertex, char *token, int row, int col)
{
	char	*comma_pos;

	if (vertex == NULL || token == NULL)
		return (1);
	if (row < 0 || col < 0)
		return (2);
	vertex->x = col;
	vertex->y = row;
	vertex->color = WHITE_COLOR;
	comma_pos = ft_strchr(token, ',');
	if (comma_pos)
		vertex->color = hex_to_int(comma_pos + 2);
	if (fdf_atoi(token, &vertex->z) != 0)
		return (3);
	return (0);
}
