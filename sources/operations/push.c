/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:43:16 by eraad             #+#    #+#             */
/*   Updated: 2025/02/21 22:43:16 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//* Pushes an element to the top of the stack if there is space
static	void	push(t_stack *stack, int data)
{
	if (stack_is_full(stack))
		return ;
	stack->top--;
	stack->array[stack->top] = data;
}

//* Pop the top lement of the stack by decrementing the top index
static	int	pop(t_stack *stack)
{
	int	data;

	if (stack_is_empty(stack))
		return (-5);
	data = stack->array[stack->top];
	stack->top++;
	return (data);
}

//* Pushes the top element of stack b to stack a
void	pa(t_stack	*a, t_stack	*b, t_log	*log)
{
	if (stack_is_empty(b))
		return ;
	push(a, pop(b));
	log_operations(log, "pa");
}

//* Pushes the top element of stack a to stack b
void	pb(t_stack	*b, t_stack	*a, t_log	*log)
{
	if (stack_is_empty(a))
		return ;
	push(b, pop(a));
	log_operations(log, "pb");
}
