/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 23:55:06 by omaly             #+#    #+#             */
/*   Updated: 2025/11/16 23:57:56 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void free_scene(t_vertex **scene, int rows)
{
	if (scene == NULL)
		return;
	int i = 0;
	while (i < rows)
	{
		free(scene[i]);
		i++;
	}
	free(scene);
	scene = NULL;
}
