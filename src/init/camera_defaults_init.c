/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_defaults_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:44:23 by omaly             #+#    #+#             */
/*   Updated: 2025/11/18 18:37:05 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	camera_defaults_init(t_camera *camera)
{
	if (camera == NULL)
		return (1);
	camera->zoom = ZOOM;
	camera->z_scale = Z_SCALE;
	camera->angle = ANGLE;
	camera->offset_x = WINDOW_SIZE_X / 2;
	camera->offset_y = WINDOW_SIZE_Y / 2;
	return (0);
}
