/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:49:18 by omaly             #+#    #+#             */
/*   Updated: 2025/11/17 09:33:39 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

int	parse_map(t_vertex **scene, t_map map);
int	parse_line(t_vertex **scene, char *line, int row, int cols);
int	parse_token(t_vertex *vertex, char *token, int row, int col);
int	parse_null_token(t_vertex *vertex, int row, int col);

#endif
