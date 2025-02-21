/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_initialize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 20:40:23 by eraad             #+#    #+#             */
/*   Updated: 2025/02/13 20:40:23 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	*init_1(int	argc, char	**argv)
{
	int	*array;
	int	i;

	array = stock_in_array(argc, argv);
	if (!array)
		return (NULL);
	if (error_doubles(argc, array))
	{
		free(array);
		return (NULL);
	}
	normalise(array, argc - 1);
	i = 0;
	while (i < argc - 1)
	{
		if (array[i] == -1)
		{
			free(array);
			return (NULL);
		}
		i++;
	}
	return (array);
}

// Initialize the stacks, creat an array from input, check errors, normalise the array and fill stack a, return the stacks
void	initialize(int	argc, char **argv, t_stack *a, t_stack *b)
{
	int	*array;

	array = init_1(argc, argv);
	if (!array)
		return;
	init_stack(a, argc - 1);
	init_stack(b, argc - 1);
	if (!a->array || !b->array)
		return;
	a->array = array;
	a->top = 0;
	return;
}
