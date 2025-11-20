/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:56:48 by omaly             #+#    #+#             */
/*   Updated: 2025/11/20 16:57:09 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	close_window(t_fdf *fdf)
{
	mlx_loop_end(fdf->mlx);
	return (0);
}

int	escape_press(int keysum, t_fdf *fdf)
{
	if (keysum == XK_Escape)
		mlx_loop_end(fdf->mlx);
	return (0);
}
