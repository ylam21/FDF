/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:34:37 by omaly             #+#    #+#             */
/*   Updated: 2025/11/16 22:28:37 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_freearr(char **s, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(s[i]);
		i++;
	}
	return ;
}

static char	*ft_getword(char const *s, char c, int *start)
{
	int		i;
	int		len;
	char	*word;

	while (s[*start] && s[*start] == c)
	{
		(*start)++;
	}
	i = *start;
	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
	}
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, s + *start, len + 1);
	*start = *start + len;
	return (word);
}

static int	ft_getwordcount(char const *s, char c)
{
	int	count;
	int	inword;
	int	i;

	count = 0;
	inword = 0;
	i = 0;
	while (s && s[i] != '\0')
	{
		if (s[i] != c && inword == 0)
		{
			count++;
			inword = 1;
		}
		else if (s[i] == c && inword)
			inword = 0;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		word_count;
	char	**tokens;
	int		start;
	int		i;

	word_count = ft_getwordcount(s, c);
	tokens = malloc(sizeof(char *) * (word_count + 1));
	if (!tokens)
		return (NULL);
	start = 0;
	i = 0;
	while (i < word_count)
	{
		tokens[i] = ft_getword(s, c, &start);
		if (!tokens[i])
		{
			ft_freearr(tokens, i);
			return (NULL);
		}
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}
