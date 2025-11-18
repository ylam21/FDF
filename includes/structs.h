/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 20:49:50 by omaly             #+#    #+#             */
/*   Updated: 2025/11/18 17:38:20 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

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
	char		*filename;
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
#endif
