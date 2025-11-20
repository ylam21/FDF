/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_defaults_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:44:23 by omaly             #+#    #+#             */
/*   Updated: 2025/11/20 14:52:16 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	calculate_zoom(unsigned int window_size_x, unsigned int window_size_y,
		unsigned int rows, unsigned int cols)
{
	float	zoom_x;
	float	zoom_y;
	float	base_zoom;

	base_zoom = 1;
	zoom_x = window_size_x / cols;
	zoom_y = window_size_y / rows;
	if (zoom_x <= zoom_y)
		base_zoom = zoom_x;
	else if (zoom_y < zoom_x)
		base_zoom = zoom_y;
	base_zoom = (int)base_zoom / 2;
	if (base_zoom < 1)
		base_zoom = 1;
	return (base_zoom);
}

int	camera_defaults_init(t_camera *camera, t_map map)
{
	if (camera == NULL)
		return (1);
	camera->zoom = calculate_zoom(WINDOW_SIZE_X, WINDOW_SIZE_Y, map.rows,
			map.cols);
	camera->z_scale = Z_SCALE;
	camera->angle = ANGLE;
	camera->offset_x = WINDOW_SIZE_X / 2;
	camera->offset_y = WINDOW_SIZE_Y / 2;
	return (0);
}
