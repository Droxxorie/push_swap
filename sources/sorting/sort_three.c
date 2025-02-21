/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:38:34 by eraad             #+#    #+#             */
/*   Updated: 2025/02/19 11:38:34 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack	*a, t_log	*log)
{
	int	top;
	int	middle;
	int	bottom;

	if (a->size - a->top != 3 || stack_is_sorted(a)) // 123
		return ;
	top = a->array[a->top];
	middle = a->array[a->top + 1];
	bottom = a->array[a->size - 1];
	if (top > middle && middle < bottom && top < bottom) // 213
		sa(a, log);
	else if (top > middle && middle > bottom) // 321
	{
		ra(a, log);
		sa(a, log);
	}
	else if (top > middle && middle < bottom && top > bottom) // 312
		ra(a, log);
	else if (top < middle && middle > bottom && top > bottom) // 231
		rra(a, log);
	else if (top < middle && middle > bottom && top < bottom) // 132
	{
		sa(a, log);
		ra(a, log);
	}
}
