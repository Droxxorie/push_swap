/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:18:55 by eraad             #+#    #+#             */
/*   Updated: 2025/02/15 13:18:55 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compute_base(t_stack	*stack)
{
	if (stack->size < 100)
		return (2);
	else if (stack->size < 500)
		return (3);
	else
		return (4);
}

static	int	compute_max_bits(t_stack	*stack, int	base)
{
	int	max_bits;
	int	max_value;
	
	max_bits = 32;
	max_value = stack->size - 1;
	while (max_value > 0)
	{
		max_bits++;
		max_value >>= base;
	}
	return (max_bits);
}

static	int	find_max_index(t_stack	*stack)
{
	int	i;
	int	max_index;

	i = stack->top + 1;
	max_index = stack->top;
	while (i < stack->size)
	{
		if (stack->array[i] > stack->array[max_index])
			max_index = i;
		i++;
	}
	return (max_index);
}

int	is_fully_sorted(t_stack	*stack)
{
	int	i;

	i = stack->top;
	while (i < stack->size - 1)
	{
		if (stack->array[i] > stack->array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	radix_sort(t_stack	*a, t_stack	*b, t_log	*log)
{
	int	bit;
	int	max_bits;
	int	max_index;
	int	base;

	bit = 0;
	base = compute_base(a);
	max_bits = compute_max_bits(a, base);
	while (bit < max_bits)
	{
		bits_sort(a, b, log, base, bit);
		while (b->size - b->top > 0)
		{
			max_index = find_max_index(b);
			while (b->array[b->top] > b->array[max_index])
				rb(b, log);
			pa(a, b, log);
			if (is_fully_sorted(a) && b->size - b->top == 0)
				return ;
		}
		bit++;
	}
}

