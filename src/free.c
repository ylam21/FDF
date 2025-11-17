/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 23:55:06 by omaly             #+#    #+#             */
/*   Updated: 2025/11/17 08:22:13 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void free_scene(t_vertex **scene, int rows)
{
	if (scene == NULL)
		return;
	int i = 0;
	while (i < rows)
	{
		free(scene[i]);
		i++;
	}
	free(scene);
}

void free_mlx(t_fdf *fdf)
{
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_image(fdf->mlx, fdf->img.img);
}

void free_fdf(t_fdf *fdf)
{
	if (fdf == NULL)
		return;
	free_scene(fdf->scene, fdf->map.rows);
	free_mlx(fdf);
}
