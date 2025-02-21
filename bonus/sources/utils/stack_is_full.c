/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_is_full.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:31:09 by eraad             #+#    #+#             */
/*   Updated: 2025/02/17 10:31:09 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

// Check if the stack is full by looking at top index, return 1 if full, 0 if not
int	stack_is_full(t_stack	*stack)
{
	if (stack->top == 0)
		return (1);
	return (0);
}
