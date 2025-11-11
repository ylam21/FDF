/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:20:43 by omaly             #+#    #+#             */
/*   Updated: 2025/11/11 14:56:39 by omaly            ###   ########.fr       */
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
# include "error.h"
# include "parser.h"
# include "projector.h"
# include "renderer.h"
# include "utils.h"

// Window size for mlx_new_window()
# define WINDOW_SIZE_X 1920
# define WINDOW_SIZE_Y 1080

typedef struct s_point2
{
	int			x;
	int			y;
	int			color;
}				t_point2;

typedef struct s_camera
{
	double		zoom;
	double		z_scale;
	double		angle;
	double		offset_x;
	double		offset_y;
}				t_camera;

typedef struct s_vertex
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_vertex;
typedef struct s_bresenham_state
{
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			e2;
}				t_bresenham_state;

typedef struct s_proj
{
	double		x;
	double		y;
	double		z;
}				t_proj;

typedef struct s_map
{
	int			fd;
	int			rows;
	int			cols;
}				t_map;

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_fdf
{
	void		*mlx;
	void		*win;
	t_data		img;
	t_map		map;
	t_vertex	**scene;
	t_camera	camera;

}				t_fdf;

int				fdf_init(t_fdf *fdf, char *filename);
int				has_fdf_extension(char *filename);
#endif
