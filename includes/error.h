/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:49:01 by omaly             #+#    #+#             */
/*   Updated: 2025/11/18 17:05:38 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define ERROR_ARGC "Error: Usage: ./fdf <map_file>\n"
# define ERROR_EXTENSION "Error: Only .fdf files are allowed\n"
# define ERROR_PARSE "Error: Failed to parse map file\n"
# define ERROR_MAP_INIT "Error: Failed to initialize t_map struct\n"
# define ERROR_CAMERA_INIT "Error: Failed to initialize t_camera struct\n"
# define ERROR_ALLOC_SCENE "Error: Failed to allocate scene\n"
# define ERROR_MLX_INIT "Error: Failed to initialize mlx\n"

void	exit_error(char *error_msg);
#endif
