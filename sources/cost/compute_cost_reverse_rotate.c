/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_cost_reverse_rotate.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 23:22:01 by eraad             #+#    #+#             */
/*   Updated: 2025/02/21 23:22:01 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Compute the number of rra needed to put the element in the right place in a
int	compute_n_rra(t_stack	*a, t_stack	*b, int i)
{
	int	max_index;
	int	min_index;
	int	j;

	max_index = find_max_index(a);
	min_index = find_min_index(a);
	if (b->array[i] >= a->array[max_index])
		return (a->size - max_index);
	if (b->array[i] <= a->array[min_index])
		return (a->size - min_index);
	j = a->size - 1;
	while (j > a->top)
	{
		if (a->array[j - 1] <= b->array[i] && b->array[i] <= a->array[j])
			return (a->size - j);
		j--;
	}
	return (0);
}

// Compute the number of rrb needed to put the element at the top of the stack
int	compute_n_rrb(t_stack	*b, int i)
{
	int	n_rrb;
	int	index;

	index = i - b->top;
	n_rrb = b->size - index;
	return (n_rrb);
}

// Compute the number of rrr needed to put the element in the right place in a
int	compute_n_rrr(int n_rra, int n_rrb)
{
	if (n_rra == n_rrb)
		return (n_rra);
	else if (n_rra > n_rrb)
		return (n_rrb);
	else
		return (n_rra);
}
