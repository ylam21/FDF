/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:35:52 by omaly             #+#    #+#             */
/*   Updated: 2025/11/19 11:13:58 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	close_window(t_fdf *fdf)
{
	mlx_loop_end(fdf->mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	ft_bzero(&fdf, sizeof(fdf));
	if (argc != 2)
		return (print_error(ERROR_ARGC));
	if (has_fdf_extension(argv[1]) != 1)
		return (print_error(ERROR_EXTENSION));
	if (camera_defaults_init(&fdf.camera) != 0)
		return (print_error(ERROR_CAMERA_INIT));
	if (mlx_defaults_init(&fdf) != 0)
		return (print_error(ERROR_MLX_INIT));
	if (map_defaults_init(&fdf.map, argv[1]) != 0)
		return (print_error(ERROR_MAP_INIT));
	fdf.scene = allocate_scene(fdf.map.rows, fdf.map.cols);
	if (fdf.scene == NULL)
		return (free_fdf(&fdf), print_error(ERROR_ALLOC_SCENE));
	if (parse_map(fdf.scene, fdf.map) != 0)
		return (free_fdf(&fdf), print_error(ERROR_PARSE));
	render_scene(&fdf, fdf.map);
	mlx_hook(fdf.win, 17, 0, close_window, &fdf);
	mlx_loop(fdf.mlx);
	free_fdf(&fdf);
	return (EXIT_SUCCESS);
}
