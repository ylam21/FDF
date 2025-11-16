/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:46:45 by omaly             #+#    #+#             */
/*   Updated: 2025/11/16 22:29:53 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	parse_line(t_vertex **scene, char *line, int row, int cols)
{
	char	**tokens;
	int		i;

	tokens = ft_split(line, ' ');
	if (tokens == NULL)
		return (1);
	i = 0;
	while (tokens[i] != NULL && i < cols)
	{
		if (parse_token(&scene[row][i], tokens[i], row, i) != 0)
		{
			printf("Failed to parse token 1\n");
			free_split(tokens);
			return (2);
		}
		i++;
	}
	while (i < cols)
	{
		if (parse_null_token(&scene[row][i],row, i) != 0) {
			free_split(tokens);
			return 3;
		}
		i++;
	}

	if (i != cols)
	{
		printf("Failed to parse token 2\n");
		free_split(tokens);
		return (3);
	}
	free_split(tokens);
	return (0);
}
