/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 00:29:45 by eraad             #+#    #+#             */
/*   Updated: 2025/02/20 00:29:45 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*copy_stack(t_stack	*stack)
{
	t_stack	*copy;

	if (!stack || !stack->array || stack->size <= 0)
		return (NULL);
	copy = malloc(sizeof(t_stack));
	if (!copy)
		return (NULL);
	copy->array = malloc(sizeof(int) * stack->size);
	if (!copy->array)
	{
		free(copy);
		return (NULL);
	}
	copy->size = stack->size;
	copy->top = stack->top;
	ft_memcpy(copy->array, stack->array, stack->size * sizeof(int));
	return (copy);
}
