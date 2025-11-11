/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_fdf_extension.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 12:09:05 by omaly             #+#    #+#             */
/*   Updated: 2025/11/11 12:30:40 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	has_fdf_extension(char *filename)
{
	size_t	len;

	if (filename == NULL)
		return (0);
	if (ft_strlen(filename) < 5)
		return (0);
	len = ft_strlen(filename);
	if (ft_strnstr(filename, ".fdf", len) != NULL)
		return (1);
	return (0);
}
