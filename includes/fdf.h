/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:20:43 by omaly             #+#    #+#             */
/*   Updated: 2025/11/16 20:51:00 by omaly            ###   ########.fr       */
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
// PROJECT MODULES
#include "structs.h"
# include "error.h"
# include "parser.h"
# include "projector.h"
# include "renderer.h"
# include "utils.h"

// Window size for mlx_new_window()
# define WINDOW_SIZE_X 1920
# define WINDOW_SIZE_Y 1080



int				fdf_init(t_fdf *fdf, char *filename);
int				has_fdf_extension(char *filename);
#endif
