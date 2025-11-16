/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:20:43 by omaly             #+#    #+#             */
/*   Updated: 2025/11/17 00:16:54 by omaly            ###   ########.fr       */
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
# include "parser.h"
# include "projector.h"
# include "renderer.h"
# include "utils.h"

int		fdf_init(t_fdf *fdf, char *filename);
int		has_fdf_extension(char *filename);
void	free_fdf(t_fdf *fdf);
#endif
