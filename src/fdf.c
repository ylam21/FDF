/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:35:52 by omaly             #+#    #+#             */
/*   Updated: 2025/10/18 19:49:57 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int main(void)
{
	void *mlx;
	void *mlx_window;

	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, WINDOW_SIZE_X, WINDOW_SIZE_Y, "Hello, World!\n");
	mlx_loop(mlx);

	return 0;
}
