/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:18:16 by omaly             #+#    #+#             */
/*   Updated: 2025/11/10 14:21:43 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	count_words(char *s)
{
	int	words;
	int	i;

	words = 0;
	i = 0;
	while (s && s[i] != '\0')
	{
		while (is_whitespace(s[i]))
			i++;
		if (ft_isalnum(s[i]))
			words++;
		while (ft_isalnum(s[i]))
			i++;
	}
	return (words);
}
