/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_cost_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:16:18 by eraad             #+#    #+#             */
/*   Updated: 2025/02/19 14:16:18 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Compute the number of ra needed to put the element in the right place in a
int	compute_n_ra(t_stack	*a, t_stack	*b, int	i)
{
	int	max_index;
	int	min_index;
	int	j;
	
	max_index = find_max_index(a);
	min_index = find_min_index(a);
	if (b->array[i] >= a->array[max_index])
		return (max_index - a->top);
	if (b->array[i] <= a->array[min_index])
		return (min_index - a->top);
	j = a->top;
	while (j < a->size - 1)
	{
		if (a->array[j] <= b->array[i] && b->array[i] <= a->array[j + 1])
			return (j - a->top + 1);
		j++;
	}
	return (0);
}

// Compute the number of rb needed to put the element at the top of the stack
int	compute_n_rb(t_stack	*b, int	i)
{
	int	n_rb;
	int	index;

	index = i - b->top;
	n_rb = index;
	return (n_rb);
}

// Compute the number of rr needed to put the element in the right place in a
int	compute_n_rr(int n_ra, int n_rb)
{
	if (n_ra == n_rb)
		return (n_ra);
	else if (n_ra > n_rb)
		return (n_rb);
	else
		return (n_ra);
}
