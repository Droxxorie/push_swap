/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_max_indexes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:18:49 by eraad             #+#    #+#             */
/*   Updated: 2025/02/21 22:18:49 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//* Find the minimum value in the stack
int	find_min_index(t_stack	*stack)
{
	int	min_index;
	int	i;

	i = stack->top + 1;
	min_index = stack->top;
	while (i < stack->size)
	{
		if (stack->array[i] < stack->array[min_index])
			min_index = i;
		i++;
	}
	return (min_index);
}

//* Find the maximum value in the stack
int	find_max_index(t_stack	*stack)
{
	int	max_index;
	int	i;

	i = stack->top + 1;
	max_index = stack->top;
	while (i < stack->size)
	{
		if (stack->array[i] > stack->array[max_index])
			max_index = i;
		i++;
	}
	return (max_index);
}
