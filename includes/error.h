/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:49:01 by omaly             #+#    #+#             */
/*   Updated: 2025/11/11 14:56:15 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define ERROR_ARGC "Error: Usage: ./fdf <map_file>\n"
# define ERROR_EXTENSION "Error: Only .fdf files are allowed\n"
# define ERROR_PARSE "Error: Failed to parse map file\n"
# define ERROR_INIT "Error: Failed to initialize t_fdf struct\n"

void	exit_error(char *error_msg);
#endif
