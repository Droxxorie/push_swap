/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:44:31 by eraad             #+#    #+#             */
/*   Updated: 2025/02/21 22:44:31 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

//* Reverse rotate the stack, shift down all elements of the stack by 1
static	void	reverse_rotate(t_stack	*stack)
{
	int	last;
	int	i;

	if (stack->top < 0 || stack->top > stack->size - 2)
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

//* Reverse rotate the stack a
void	rra(t_stack	*a, t_log	*log)
{
	reverse_rotate(a);
	log_operations(log, "rra");
}

//* Reverse rotate the stack b
void	rrb(t_stack	*b, t_log	*log)
{
	reverse_rotate(b);
	log_operations(log, "rrb");
}

//* Reverse rotate the stack a and b
void	rrr(t_stack	*a, t_stack	*b, t_log	*log)
{
	reverse_rotate(a);
	reverse_rotate(b);
	log_operations(log, "rrr");
}
