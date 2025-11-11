/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:57:52 by omaly             #+#    #+#             */
/*   Updated: 2025/11/11 12:00:20 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

typedef struct s_proj {
	double x;
	double y;
	double z;
}	t_proj;

t_point2 project_vertex(t_camera *camera, t_map *map, t_vertex *v)
{
	t_point2 p2;
	t_proj p3;

	p3.x = v->x - map->cols / 2.0;
	p3.y = v->y - map->rows / 2.0;
	p3.z = v->z * camera->z_scale;

	p2.x = (int)((p3.x - p3.y) * cos(camera->angle) * camera->zoom + camera->offset_x);
	p2.y = (int)((p3.x + p3.y) * sin(camera->angle) * camera->zoom - p3.z * camera->zoom + camera->offset_y);
	p2.color = v->color;
	return (p2);
}
