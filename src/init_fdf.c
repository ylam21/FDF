/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 19:51:52 by omaly             #+#    #+#             */
/*   Updated: 2025/10/29 20:18:32 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int open_map(char *map)
{
	int fd;
	if (!map)
		return 1;
	else if (ft_strnstr(map, ".fdf", 4) == NULL) {
		ft_putstr_fd("no .fdf extension\n",2);
		return 2;
	}
	fd = open(map, O_RDONLY);
	if (fd < 0) {
		perror("open");
		return 3;
	}
	return fd;
}

int init_fdf(t_fdf fdf, int argc, char **argv)
{
	if (argc != 2)
		return 1;
	fdf.file = open_map(argv[1]);
	if (fdf.file != 0)
		return 2;
	return 0;
}
