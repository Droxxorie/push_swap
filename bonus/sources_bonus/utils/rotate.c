/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:44:47 by eraad             #+#    #+#             */
/*   Updated: 2025/02/21 22:44:47 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

//* Rotate the stack, shift up all elements of the stack by 1
static	void	rotate(t_stack	*stack)
{
	int	first;
	int	i;

	if (stack->top >= stack->size - 1)
		return ;
	first = stack->array[stack->top];
	i = stack->top;
	while (i < stack->size - 1)
	{
		stack->array[i] = stack->array[i + 1];
		i++;
	}
	stack->array[stack->size - 1] = first;
}

//* Rotate the stack a
void	ra(t_stack	*a, t_log	*log)
{
	rotate(a);
	log_operations(log, "ra");
}

//* Rotate the stack b
void	rb(t_stack	*b, t_log	*log)
{
	rotate(b);
	log_operations(log, "rb");
}

//* Rotate the stack a and b
void	rr(t_stack	*a, t_stack	*b, t_log	*log)
{
	rotate(a);
	rotate(b);
	log_operations(log, "rr");
}
