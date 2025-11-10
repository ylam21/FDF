/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:49:01 by omaly             #+#    #+#             */
/*   Updated: 2025/11/10 12:30:10 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define ERROR_ARGC "Error: Usage: ./fdf <map_file>\n"
# define ERROR_EXTENSION "Error: Only .fdf files are allowed\n"
void exit_error(char *error_msg);
#endif
