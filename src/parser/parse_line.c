/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:46:45 by omaly             #+#    #+#             */
/*   Updated: 2025/11/10 15:47:04 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	parse_line(t_vertex **scene, char *line, int curr_row, int cols)
{
	char	**tokens;
	int		i;

	tokens = ft_split(line, ' ');
	if (tokens == NULL)
		return (1);
	i = 0;
	while (tokens[i] != NULL && i < cols)
	{
		if (parse_token(&scene[curr_row][i], tokens[i], curr_row, i) != 0)
		{
			free_split(tokens);
			return (2);
		}
		i++;
	}
	if (i != cols || tokens[i] != NULL)
	{
		free_split(tokens);
		return (3);
	}
	free_split(tokens);
	return (0);
}
