/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_insertion_sort.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:59:09 by eraad             #+#    #+#             */
/*   Updated: 2025/02/21 22:59:09 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//* Compute the cost of the operations needed to insert an element into a
//* and select the best element to insert
void	dynamic_insertion_sort(t_stack *a, t_stack *b, t_log *log)
{
	int	cost[7];
	int	temp[7];
	int	i;
	int	j;

	while (!stack_is_empty(b))
	{
		compute_cost(a, b, b->top, cost);
		i = b->top + 1;
		while (i < b->size)
		{
			compute_cost(a, b, i, temp);
			if (temp[0] < cost[0])
			{
				j = 0;
				while (j < 7)
				{
					cost[j] = temp[j];
					j++;
				}
			}
			i++;
		}
		do_op(a, b, log, cost);
	}
}
