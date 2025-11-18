/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 23:55:06 by omaly             #+#    #+#             */
/*   Updated: 2025/11/18 18:03:00 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	free_scene(t_vertex **scene, int rows)
{
	int	i;

	if (scene == NULL)
		return ;
	i = 0;
	while (i < rows)
	{
		free(scene[i]);
		i++;
	}
	free(scene);
}

void	free_mlx(t_fdf *fdf)
{
	if (fdf->win)
		mlx_destroy_window(fdf->mlx, fdf->win);
	if (fdf->img.img)
		mlx_destroy_image(fdf->mlx, fdf->img.img);
	if (fdf->mlx)
	{
		mlx_destroy_display(fdf->mlx);
		free(fdf->mlx);
	}
}

void	free_fdf(t_fdf *fdf)
{
	if (fdf == NULL)
		return ;
	free(fdf->map.filename);
	free_scene(fdf->scene, fdf->map.rows);
	free_mlx(fdf);
}
