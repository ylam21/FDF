/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:14:24 by omaly             #+#    #+#             */
/*   Updated: 2025/11/10 15:14:52 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	hex_to_int(const char *hex_str)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (hex_str && hex_str[i])
	{
		result *= 16;
		if (hex_str[i] >= '0' && hex_str[i] <= '9')
			result += hex_str[i] - '0';
		else if (hex_str[i] >= 'A' && hex_str[i] <= 'F')
			result += hex_str[i] - 'A' + 10;
		else if (hex_str[i] >= 'a' && hex_str[i] <= 'f')
			result += hex_str[i] - 'a' + 10;
		i++;
	}
	return (result);
}
