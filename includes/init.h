/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:52:35 by omaly             #+#    #+#             */
/*   Updated: 2025/11/19 17:02:59 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

int	camera_defaults_init(t_camera *camera, t_map map);
int	map_defaults_init(t_map *map, char *filename);
int	mlx_defaults_init(t_fdf *fdf);

#endif
