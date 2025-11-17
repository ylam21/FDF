/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:47:21 by omaly             #+#    #+#             */
/*   Updated: 2025/11/17 09:43:45 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	render_point_neighbors(t_fdf *fdf, int row, int col)
{
	t_point2	p;
	t_point2	right;
	t_point2	down;

	p = project_vertex(fdf->camera, fdf->map, fdf->scene[row][col]);
	if (col + 1 < fdf->map.cols)
	{
		right = project_vertex(fdf->camera, fdf->map, fdf->scene[row][col + 1]);
		draw_line(fdf, p, right);
	}
	if (row + 1 < fdf->map.rows)
	{
		down = project_vertex(fdf->camera, fdf->map, fdf->scene[row + 1][col]);
		draw_line(fdf, p, down);
	}
}

void	render_scene(t_fdf *fdf, t_map map)
{
	int	row;
	int	col;

	row = 0;
	while (row < map.rows)
	{
		col = 0;
		while (col < map.cols)
		{
			render_point_neighbors(fdf, row, col);
			col++;
		}
		row++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.img, 0, 0);
}
