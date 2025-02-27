/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 23:04:11 by eraad             #+#    #+#             */
/*   Updated: 2025/02/21 23:04:11 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//* Sort three elements in the stack a using the minimum number of operations
void	sort_three(t_stack	*a, t_log	*log)
{
	int	top;
	int	middle;
	int	bottom;

	if (a->size - a->top != 3 || stack_is_sorted(a))
		return ;
	top = a->array[a->top];
	middle = a->array[a->top + 1];
	bottom = a->array[a->size - 1];
	if (top > middle && middle < bottom && top < bottom)
		sa(a, log);
	else if (top > middle && middle > bottom)
	{
		ra(a, log);
		sa(a, log);
	}
	else if (top > middle && middle < bottom && top > bottom)
		ra(a, log);
	else if (top < middle && middle > bottom && top > bottom)
		rra(a, log);
	else if (top < middle && middle > bottom && top < bottom)
	{
		sa(a, log);
		ra(a, log);
	}
}
