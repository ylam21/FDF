/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 19:51:52 by omaly             #+#    #+#             */
/*   Updated: 2025/11/10 12:34:55 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void get_map_dimensions(t_map *map)
{

}

t_map get_map_data(char *filename)
{
	t_map map;

	map.rows = 0;
	map.cols = 0;
	map.fd = open(filename, O_RDONLY);
	if (map.fd < 0) {
		perror(filename);
		exit_error(EXIT_FAILURE);
	}
	get_map_dimensions(&map);
	return map;
}

int fdf_init(t_fdf *fdf, char *filename)
{
	fdf->map = get_map_data(filename);
	fdf->scene = allocate_scene(fdf->map.rows, fdf->map.cols);
	return 0;
}
