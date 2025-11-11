/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:26:16 by omaly             #+#    #+#             */
/*   Updated: 2025/11/11 11:46:47 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

typedef struct s_bresenham_state {
	int dx;
	int dy;
	int sx;
	int sy;
	int err;
	int e2;
}	t_bresenham_state;

static void	put_pixel(t_fdf *fdf, int x, int y, int color)
{
	if (x >= 0 && x < WINDOW_SIZE_X && y >= 0 && y < WINDOW_SIZE_Y)
		mlx_pixel_put(fdf->mlx, fdf->img, x, y, color);
}

void	draw_line(t_fdf *fdf, t_point2 a, t_point2 b)
{
	t_bresenham_state state;

	state.dx = abs(b.x - a.x);
	state.dy = -abs(b.y - a.y);
	state.sx = (a.x < b.x) ? 1 : -1;
	state.sy = (a.y < b.y) ? 1 : -1;
	state.err = state.dx + state.dy;

	while (1)
	{
		put_pixel(fdf, a.x, a.y, a.color);
		if (a.x == b.x && a.y == b.y)
			break ;
		state.e2 = 2 * state.err;
		if (state.e2 >= state.dy)
		{
			state.err += state.dy;
			a.x += state.sx;
		}
		if (state.e2 <= state.dx)
		{
			state.err += state.dx;
			a.y += state.sy;
		}
	}
}
