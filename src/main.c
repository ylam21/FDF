/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:35:52 by omaly             #+#    #+#             */
/*   Updated: 2025/11/20 17:03:27 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	ft_bzero(&fdf, sizeof(fdf));
	if (argc != 2)
		return (print_error(ERROR_ARGC));
	if (has_fdf_extension(argv[1]) != 1)
		return (print_error(ERROR_EXTENSION));
	if (map_defaults_init(&fdf.map, argv[1]) != 0)
		return (print_error(ERROR_MAP_INIT));
	if (mlx_defaults_init(&fdf) != 0)
		return (free_fdf(&fdf), print_error(ERROR_MLX_INIT));
	if (camera_defaults_init(&fdf.camera, fdf.map) != 0)
		return (free_fdf(&fdf), print_error(ERROR_CAMERA_INIT));
	fdf.scene = allocate_scene(fdf.map.rows, fdf.map.cols);
	if (fdf.scene == NULL)
		return (free_fdf(&fdf), print_error(ERROR_ALLOC_SCENE));
	if (parse_map(fdf.scene, fdf.map) != 0)
		return (free_fdf(&fdf), print_error(ERROR_PARSE));
	render_scene(&fdf, fdf.map);
	mlx_hook(fdf.win, COPY_DESTRYNOTIFY, COPY_NOEVENTMASK, &close_window,
		&fdf);
	mlx_hook(fdf.win, COPY_KEYPRESS, (1L << 0), &escape_press, &fdf);
	mlx_loop(fdf.mlx);
	free_fdf(&fdf);
	return (EXIT_SUCCESS);
}
