/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 19:51:52 by omaly             #+#    #+#             */
/*   Updated: 2025/11/10 14:38:32 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	get_map_dimensions(t_map *map)
{
	int		cols;
	int		rows;
	char	*line;
	int		tmp_col_count;

	rows = 0;
	cols = 0;
	line = get_next_line(map->fd);
	while (line != NULL)
	{
		tmp_col_count = count_words(line);
		if (cols < tmp_col_count)
			cols = tmp_col_count;
		rows++;
		line = get_next_line(map->fd);
	}
	map->rows = rows;
	map->cols = cols;
	return (0);
}

int	get_map_data(t_map *map, char *filename)
{
	map->fd = open(filename, O_RDONLY);
	if (map->fd < 0)
	{
		perror(filename);
		return (1);
	}
	if (get_map_dimensions(map) != 0)
		return (2);
	return (0);
}

int	allocate_scene(t_vertex ***scene, int rows, int cols)
{
	int	i;
	int	n;

	*scene = malloc(sizeof(t_vertex *) * rows);
	if (*scene == NULL)
		return (1);
	i = 0;
	while (i < rows)
	{
		(*scene)[i] = malloc(sizeof(t_vertex) * cols);
		if ((*scene)[i] == NULL)
		{
			n = 0;
			while (n < i)
			{
				free(*(scene)[n]);
				n++;
			}
			free(*scene);
			*scene = NULL;
			return (2);
		}
		i++;
	}
	return (0);
}

int	fdf_init(t_fdf *fdf, char *filename)
{
	if (get_map_data(fdf->map, filename) != 0)
		return (1);
	if (allocate_scene(&fdf->scene, fdf->map->rows, fdf->map->cols) != 0)
		return (2);
	return (0);
}
