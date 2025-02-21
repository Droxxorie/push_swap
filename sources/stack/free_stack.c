/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 23:02:54 by eraad             #+#    #+#             */
/*   Updated: 2025/02/20 23:02:54 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack	*stack)
{
	if (!stack)
		return;
	if (stack->array)
	{
		free(stack->array);
		stack->array = NULL;
	}
}
