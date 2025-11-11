/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:35:52 by omaly             #+#    #+#             */
/*   Updated: 2025/11/11 12:31:11 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc < 2)
		exit_error(ERROR_ARGC);
	if (has_fdf_extension(argv[1]) != 1)
		exit_error(ERROR_EXTENSION);
	if (fdf_init(&fdf, argv[1]) != 0)
		exit_error(ERROR_INIT);
	if (parse_map(fdf.scene, fdf.map) != 0)
		exit_error(ERROR_PARSE);

	render_scene(&fdf);
	mlx_loop(fdf.mlx);

	return (0);
}
