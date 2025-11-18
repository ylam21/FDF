/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:20:43 by omaly             #+#    #+#             */
/*   Updated: 2025/11/18 17:28:39 by omaly            ###   ########.fr       */
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
# include "structs.h"
# include "error.h"
# include "init.h"
# include "parser.h"
# include "projector.h"
# include "renderer.h"
# include "utils.h"

int			has_fdf_extension(char *filename);
t_vertex	**allocate_scene(int rows, int cols);
#endif
