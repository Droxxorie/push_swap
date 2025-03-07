/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_create_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 09:05:20 by eraad             #+#    #+#             */
/*   Updated: 2025/03/07 09:05:20 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

//* Check if the number is zero
static int	is_zero(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if ((str[i] == '+' || str[i] == '-') && str[i + 1])
		i++;
	while (str[i])
	{
		if (str[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

static void	free_split(char **words, int words_count)
{
	int	i;

	i = 0;
	while (i < words_count)
	{
		free(words[i]);
		i++;
	}
	free(words);
}

static int	*handle_error(int *array, char **words, int words_count)
{
	free(array);
	free_split(words, words_count);
	return (NULL);
}

//* Create an array from the input
int	*create_array(int argc, char **argv)
{
	int	i;
	int	*array;

	array = malloc((argc - 1) * sizeof(int));
	if (!array)
		return (NULL);
	i = 1;
	while (i < argc - 1)
	{
		if (argv[i][0] == '\0')
		{
			free(array);
			return (NULL);
		}
		array[i] = ft_atoi_long(argv[i]);
		if (array[i] == 0 && !is_zero(argv[i]))
		{
			free(array);
			return (NULL);
		}
		i++;
	}
	return (array);
}

//* Create an array, split the string only if argc == 2
//* and the string contains spaces
//* if not, call create_array
int	*create_array_split(int argc, char **argv)
{
	int		i;
	int		*array;
	char	**words;

	words = ft_split(argv[1], ' ');
	if (!words)
		return (NULL);
	array = malloc(argc * sizeof(int));
	if (!array)
		return (handle_error(NULL, words, argc - 1));
	i = -1;
	while (++i < argc - 1)
	{
		array[i] = ft_atoi_long(words[i]);
		if (words[i][0] == '\0' || (array[i] == 0 && !is_zero(words[i])))
			return (handle_error(array, words, argc - 1));
	}
	free_split(words, argc - 1);
	return (array);
}
