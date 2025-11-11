/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:49:18 by omaly             #+#    #+#             */
/*   Updated: 2025/11/11 14:54:48 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "fdf.h"

int	parse_map(t_vertex **scene, t_map map);
int	parse_line(t_vertex **scene, char *line, int curr_row, int cols);
int	parse_token(t_vertex *vertex, char *token, int row, int col);

#endif
