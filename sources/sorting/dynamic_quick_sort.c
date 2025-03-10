/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_quick_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:59:38 by eraad             #+#    #+#             */
/*   Updated: 2025/02/21 22:59:38 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//* Compute the index of the element at the percentile
static	int	find_percentile(t_stack	*stack, int percentile)
{
	int	index;
	int	size;

	size = stack->size - stack->top;
	index = (size * percentile / 100);
	if (index >= size)
		index = size - 1;
	return (stack->top + index);
}

//* Quick sort the stack a and push the elements to stack b
//* based on the percentile
void	dynamic_quick_sort(t_stack *a, t_stack	*b, t_log *log, int *p)
{
	int	pivot_1;
	int	pivot_2;
	int	height;

	while (a->size - a->top > 3)
	{
		pivot_1 = find_percentile(a, p[0]);
		pivot_2 = find_percentile(a, p[1]);
		height = a->size - a->top - 1;
		while (height > 0 && a->size - a->top > 3)
		{
			if (a->array[a->top] < pivot_1)
			{
				pb(b, a, log);
				rb(b, log);
			}
			else if (a->array[a->top] <= pivot_2)
				pb(b, a, log);
			else
				ra(a, log);
			height--;
		}
	}
}
