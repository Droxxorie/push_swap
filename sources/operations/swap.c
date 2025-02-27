/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:45:10 by eraad             #+#    #+#             */
/*   Updated: 2025/02/21 22:45:10 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//* Swap the top two elements of the stack
static	void	swap(t_stack	*stack)
{
	int	temp;

	if (stack->size < 2 || stack->top > stack->size - 2)
		return ;
	if (stack->top >= 0)
	{
		temp = stack->array[stack->top];
		stack->array[stack->top] = stack->array[stack->top + 1];
		stack->array[stack->top + 1] = temp;
	}
}

//* Swap the top two elements of stack a
void	sa(t_stack	*a, t_log	*log)
{
	swap(a);
	log_operations(log, "sa");
}

//* Swap the top two elements of stack b
void	sb(t_stack	*b, t_log	*log)
{
	swap(b);
	log_operations(log, "sb");
}

//* Swap the top two elements of stack a and b
void	ss(t_stack	*a, t_stack	*b, t_log	*log)
{
	swap(a);
	swap(b);
	log_operations(log, "ss");
}
