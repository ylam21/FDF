/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 12:02:59 by omaly             #+#    #+#             */
/*   Updated: 2025/11/17 09:43:53 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "fdf.h"
// Window size for mlx_new_window()
# define WINDOW_SIZE_X 1920
# define WINDOW_SIZE_Y 1080
# define WHITE_COLOR 0xFFFFFFFF

void	render_scene(t_fdf *fdf, t_map map);
void	draw_line(t_fdf *fdf, t_point2 a, t_point2 b);

#endif
