/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:34:37 by omaly             #+#    #+#             */
/*   Updated: 2025/11/19 11:38:14 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_split(char **tokens)
{
	size_t	i;

	i = 0;
	if (!tokens)
		return ;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

char	*get_word(char const *s, char c, int *start)
{
	size_t	i;
	size_t	len;
	char	*word;

	if (s == NULL)
		return (NULL);
	while (s[*start] && s[*start] == c)
		(*start)++;
	i = *start;
	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
	}
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, s + *start, len + 1);
	*start = *start + len;
	return (word);
}

size_t	count_tokens(char const *s, char c)
{
	size_t	count;
	int		inword;
	size_t	i;

	if (s == NULL)
		return (0);
	count = 0;
	inword = 0;
	i = 0;
	while (s[i] != '\0')
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
	size_t	token_count;
	char	**tokens;
	int		start;
	size_t	i;

	if (s == NULL)
		return (NULL);
	token_count = count_tokens(s, c);
	tokens = malloc(sizeof(char *) * (token_count + 1));
	if (!tokens)
		return (NULL);
	start = 0;
	i = 0;
	while (i < token_count)
	{
		tokens[i] = get_word(s, c, &start);
		if (!tokens[i])
		{
			free_split(tokens);
			return (NULL);
		}
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}
