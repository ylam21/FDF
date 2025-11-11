/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:57:48 by omaly             #+#    #+#             */
/*   Updated: 2025/11/11 12:08:55 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTOR_H
#define PROJECTOR_H

#include "fdf.h"

t_point2 project_vertex(t_camera *camera, t_map *map, t_vertex *v);

#endif
