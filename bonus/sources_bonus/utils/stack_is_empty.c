/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_is_empty.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:23:02 by eraad             #+#    #+#             */
/*   Updated: 2025/02/21 22:23:02 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

// Check if the stack is empty by looking at top, return 1 if empty, 0 if not
int	stack_is_empty(t_stack	*stack)
{
	if (stack->top >= stack->size)
		return (1);
	return (0);
}
