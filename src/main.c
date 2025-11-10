/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:35:52 by omaly             #+#    #+#             */
/*   Updated: 2025/11/10 12:38:20 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc < 2)
	{
		exit_error(ERROR_ARGC);
	}
	if (has_fdf_extension(argv[1]) != 1)
	{
		exit_error(ERROR_EXTENSION);
	}
	if (fdf_init(&fdf,argv[1]) != 0)
	{

		return (1);
	}
	if (parse_map() != 0)
		return (2);
	return (0);
}
