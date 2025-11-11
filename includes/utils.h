/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:19:33 by omaly             #+#    #+#             */
/*   Updated: 2025/11/11 14:54:59 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../src/utils/gnl/get_next_line.h"

int		is_whitespace(char c);
int		count_words(char *s);
int		fdf_atoi(const char *s, int *out);
int		hex_to_int(const char *hex_str);
void	free_split(char **split);
#endif
