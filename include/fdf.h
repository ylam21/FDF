/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:20:43 by omaly             #+#    #+#             */
/*   Updated: 2025/11/10 12:36:09 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include "../lib/libft/libft.h"
#include "../lib/gnl/get_next_line.h"
#include "../lib/mlx/mlx.h"
#include "../lib/mlx/mlx_int.h"

#include <fcntl.h>

// Window size for mlx_new_window()
#define WINDOW_SIZE_X 1920
#define WINDOW_SIZE_Y 1080

// PROJECT MODULES
#include "error.h"

typedef struct s_vertex {
	double x;
	double y;
	double z;
	int color;
}	t_vertex;

typedef struct s_map {
	int fd;
	int rows;
	int cols;
} t_map;

typedef struct s_fdf {
	t_map map;
	t_vertex **scene;
} t_fdf;

int fdf_init(char *filename);
int has_fdf_extension(char *filename);
#endif
