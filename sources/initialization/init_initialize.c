/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_initialize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:38:32 by eraad             #+#    #+#             */
/*   Updated: 2025/02/21 22:38:32 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	*create_array(int argc, char **argv)
{
	int	i;
	int	*array;

	array = malloc((argc - 1) * sizeof(int));
	if (!array)
		return (NULL);
	i = 0;
	while (i < argc - 1)
	{
		array[i] = ft_atoi_long(argv[i + 1]);
		if (array[i] == 0 && argv[i + 1][0] != '0')
		{
			free(array);
			return (NULL);
		}
		i++;
	}
	return (array);
}

static	int	*init_1(int argc, char	**argv)
{
	int	*array;
	int	i;

	array = create_array(argc, argv);
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

static	void	stack_in_stack(t_stack	*stack, int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		stack->array[i] = array[i];
		i++;
	}
	free(array);
}

// Initialize the stacks, creat an array from input, check errors
// normalise the array and fill stack a, return the stacks
void	initialize(int argc, char **argv, t_stack *a, t_stack *b)
{
	int	*array;

	array = init_1(argc, argv);
	if (!array)
		return ;
	init_stack(a, argc - 1);
	init_stack(b, argc - 1);
	if (!a->array || !b->array)
		return ;
	stack_in_stack(a, array, argc - 1);
	a->top = 0;
	return ;
}
