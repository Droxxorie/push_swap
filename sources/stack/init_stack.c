/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:21:04 by eraad             #+#    #+#             */
/*   Updated: 2025/02/21 22:21:04 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//* Initialize the stack
void	init_stack(t_stack	*stack, int size)
{
	if (!stack)
		return ;
	stack->top = size;
	stack->size = size;
	stack->array = (int *)malloc(sizeof(int) * size);
	if (!stack->array)
		return ;
}
