/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_defaults_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:33:32 by omaly             #+#    #+#             */
/*   Updated: 2025/11/20 16:25:49 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	mlx_defaults_init(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	if (fdf->mlx == NULL)
		return (1);
	fdf->win = mlx_new_window(fdf->mlx, WINDOW_SIZE_X, WINDOW_SIZE_Y, "FDF");
	if (fdf->win == NULL)
		return (2);
	fdf->img.img = mlx_new_image(fdf->mlx, WINDOW_SIZE_X, WINDOW_SIZE_Y);
	if (fdf->img.img == NULL)
		return (3);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img, &fdf->img.bits_per_pixel,
			&fdf->img.line_length, &fdf->img.endian);
	if (fdf->img.addr == NULL)
		return (4);
	return (0);
}
