/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:30:15 by eraad             #+#    #+#             */
/*   Updated: 2025/03/06 22:30:15 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_words(char const *s, char sep)
{
	int	words;

	words = 0;
	while (*s)
	{
		while (*s == sep)
			s++;
		if (*s)
		{
			words++;
			while (*s && *s != sep)
				s++;
		}
	}
	return (words);
}

static char	*create_word(char const *s, int len)
{
	char	*word;
	int		i;

	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**fill_array(char **array, char const *s, char sep, int words)
{
	int	i;
	int	j;

	i = 0;
	while (*s && i < words)
	{
		while (*s == sep)
			s++;
		j = 0;
		while (s[j] && s[j] != sep)
			j++;
		array[i] = create_word(s, j);
		if (!array[i])
		{
			while (--i >= 0)
				free(array[i]);
			free(array);
			return (NULL);
		}
		i++;
		s += j;
	}
	array[i] = NULL;
	return (array);
}

char	**ft_split(char const *s, char sep)
{
	char	**array;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, sep);
	array = malloc(sizeof(char *) * (words + 1));
	if (!array)
		return (NULL);
	if (!fill_array(array, s, sep, words))
		return (NULL);
	return (array);
}
