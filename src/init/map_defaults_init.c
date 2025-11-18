/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_defaults_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:42:36 by omaly             #+#    #+#             */
/*   Updated: 2025/11/18 18:16:45 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

t_map	get_map_dimensions(int fd)
{
	t_map	map;
	int		cols;
	int		rows;
	char	*line;
	int		tmp_col_count;

	rows = 0;
	cols = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		tmp_col_count = count_words(line);
		free(line);
		if (cols < tmp_col_count)
			cols = tmp_col_count;
		rows++;
		line = get_next_line(fd);
	}
	map.rows = rows;
	map.cols = cols;
	return (map);
}

int	map_defaults_init(t_map *map, char *filename)
{
	int		fd;
	t_map	tmp;

	map->rows = 0;
	map->cols = 0;
	map->filename = ft_strdup((const char *)filename);
	if (map->filename == NULL)
		return (1);
	fd = open(map->filename, O_RDONLY);
	if (fd == -1)
	{
		perror(map->filename);
		free(map->filename);
		return (2);
	}
	tmp = get_map_dimensions(fd);
	close(fd);
	map->rows = tmp.rows;
	map->cols = tmp.cols;
	return (0);
}
