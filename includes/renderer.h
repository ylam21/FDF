/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 12:02:59 by omaly             #+#    #+#             */
/*   Updated: 2025/11/11 12:15:28 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
#define RENDERER_H

#include "fdf.h"

void render_scene(t_fdf *fdf);
void	draw_line(t_fdf *fdf, t_point2 a, t_point2 b);
#endif
