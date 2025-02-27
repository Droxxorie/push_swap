/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_is_full.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:23:51 by eraad             #+#    #+#             */
/*   Updated: 2025/02/21 22:23:51 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//* Check if the stack is full by looking at top, return 1 if full, 0 if not
int	stack_is_full(t_stack	*stack)
{
	if (stack->top == 0)
		return (1);
	return (0);
}
