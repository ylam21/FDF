/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:20:43 by omaly             #+#    #+#             */
/*   Updated: 2025/11/18 18:43:35 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../lib/libft/libft.h"
# include "../lib/mlx/mlx.h"
# include "../lib/mlx/mlx_int.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdlib.h>
# include "structs.h"
# include "error.h"
# include "init.h"
# include "parser.h"
# include "projector.h"
# include "renderer.h"
# include "utils.h"
# define WINDOW_SIZE_X 1920
# define WINDOW_SIZE_Y 1080
# define ZOOM 30
# define Z_SCALE 1.0
# define ANGLE 0.8
int			has_fdf_extension(char *filename);
t_vertex	**allocate_scene(int rows, int cols);
#endif
