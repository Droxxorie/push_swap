/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:44:24 by eraad             #+#    #+#             */
/*   Updated: 2025/02/14 15:44:24 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

// initialise stack, top is the index of top element in allocated array, size is the size of the array
void	init_stack(t_stack *stack, int	size)
{
	if (!stack)
		return;
	stack->top = size;
	stack->size = size;
	stack->array = (int	*)malloc(sizeof(int) * size);
	if (!stack->array)
		return;
}
