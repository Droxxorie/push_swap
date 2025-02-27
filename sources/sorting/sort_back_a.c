/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_back_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 23:03:58 by eraad             #+#    #+#             */
/*   Updated: 2025/02/21 23:03:58 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//* sort back the stack a by ra or rra depending on the index of the min
void	sort_back_a(t_stack	*a, t_log	*log)
{
	int	min_index;
	int	rotations;

	min_index = find_min_index(a);
	rotations = min_index - a->top;
	if (rotations < (a->size - a->top) / 2)
	{
		while (rotations-- > 0)
			ra(a, log);
	}
	else
	{
		rotations = a->size - a->top - min_index;
		while (rotations-- > 0)
			rra(a, log);
	}
}
