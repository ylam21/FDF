/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:40:19 by omaly             #+#    #+#             */
/*   Updated: 2025/11/18 17:28:15 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_vertex	**allocate_scene(int rows, int cols)
{
	t_vertex	**scene;
	int			i;
	int			n;

	scene = malloc(sizeof(t_vertex *) * rows);
	if (scene == NULL)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		scene[i] = malloc(sizeof(t_vertex) * cols);
		if (scene[i] == NULL)
		{
			n = 0;
			while (n < i)
				free(scene[n++]);
			free(scene);
			return (NULL);
		}
		i++;
	}
	return (scene);
}
