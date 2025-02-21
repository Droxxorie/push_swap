/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 10:24:33 by eraad             #+#    #+#             */
/*   Updated: 2025/02/15 10:24:33 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static	void	reverse_rotate(t_stack	*stack)
{
	int	last;
	int	i;

	if (stack->top < 1)
		return ;
	last = stack->array[stack->size - 1];
	i = stack->size - 1;
	while (i > stack->top)
	{
		stack->array[i] = stack->array[i - 1];
		i--;
	}
	stack->array[stack->top] = last;
}

void	rra(t_stack	*a, t_log	*log)
{
	reverse_rotate(a);
	log_operations(log, "rra");
}

void	rrb(t_stack	*b, t_log	*log)
{
	reverse_rotate(b);
	log_operations(log, "rrb");
}

void	rrr(t_stack	*a, t_stack	*b, t_log	*log)
{
	reverse_rotate(a);
	reverse_rotate(b);
	log_operations(log, "rrr");
}
