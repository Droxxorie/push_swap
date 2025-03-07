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

#include "checker.h"

static int	*handle_error_array(int *array)
{
	free(array);
	return (NULL);
}

//* Initialize the stacks, creat an array from input, check errors
//* normalise the array and fill stack a, return the stacks
static int	*init_1(int argc, char **argv)
{
	int	*array;
	int	i;

	if (argc == 2)
	{
		argc = count_words(argv[1], ' ') + 1;
		array = create_array_split(argc, argv);
	}
	else
		array = create_array(argc, argv);
	if (!array)
		return (NULL);
	if (error_doubles(argc, array))
		return (handle_error_array(array));
	normalise(array, argc - 1);
	i = -1;
	while (++i < argc - 1)
	{
		if (array[i] == -1)
			return (handle_error_array(array));
	}
	return (array);
}

//* Stock the array in the stack
static void	stock_in_stack(t_stack *stack, int *array, int size)
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

//* Initialize the stacks, creat an array from input, check errors
//* normalise the array and fill stack a, return the stacks
void	initialize(int argc, char **argv, t_stack *a, t_stack *b)
{
	int	*array;

	array = init_1(argc, argv);
	if (argc == 2)
		argc = count_words(argv[1], ' ') + 1;
	if (!array)
	{
		a->array = NULL;
		b->array = NULL;
		return ;
	}
	init_stack(a, argc - 1);
	init_stack(b, argc - 1);
	if (!a->array || !b->array)
	{
		a->array = NULL;
		b->array = NULL;
		free(array);
		return ;
	}
	stock_in_stack(a, array, argc - 1);
	a->top = 0;
	return ;
}
