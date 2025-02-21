/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_insertion_sort.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 21:03:55 by eraad             #+#    #+#             */
/*   Updated: 2025/02/20 21:03:55 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void dynamic_insertion_sort(t_stack *a, t_stack *b, t_log *log)
{
	int	*cost;
	int	i;
	int *temp;

	while (!stack_is_empty(b))
	{
		cost = compute_cost(a, b, b->top);
		i = b->top + 1;
		while (i < b->size)
		{
			temp = compute_cost(a, b, i);
			if (temp[0] < cost[0])
			{
				free(cost);
				cost = temp;
			}
			else
				free(temp);
			i++;
		}
		do_op(a, b, log, cost);
	}
	free(cost);
}
