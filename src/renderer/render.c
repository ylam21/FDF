/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:47:21 by omaly             #+#    #+#             */
/*   Updated: 2025/11/11 12:23:24 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void render_scene(t_fdf *fdf)
{
	int row;
	int col;
	t_point2 p;
	t_point2 right;
	t_point2 down;

	row = 0;
	while (row < fdf->map->rows)
	{
		col = 0;
		while (col < fdf->map->cols)
		{
			p = project_vertex(fdf->camera, fdf->map, &fdf->scene[row][col]);
			if (col + 1 < fdf->map->cols)
			{
				right = project_vertex(fdf->camera, fdf->map, &fdf->scene[row][col + 1]);
				draw_line(fdf, p, right);
			}
			if (row + 1 < fdf->map->rows)
			{
				down = project_vertex(fdf->camera, fdf->map, &fdf->scene[row + 1][col]);
				draw_line(fdf, p, down);
			}
			col++;
		}
		row++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}
