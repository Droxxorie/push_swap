/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:19:49 by eraad             #+#    #+#             */
/*   Updated: 2025/02/15 13:19:49 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static	void	partition_pivot(t_stack	*a, t_stack	*b, int	pivot1, int	pivot2, t_log	*log)
// {
// 	int	i;
// 	int	size;

// 	i = 0;
// 	size = a->top + 1;
// 	while (i < size)
// 	{
// 		if (a->array[a->top] < pivot1)
// 			pb(b, a, log);
// 		else if (a->array[a->top] < pivot2)
// 			ra(a, log);
// 		else
// 			rra(a, log);
// 		i++;
// 	}
// }

static	int	*partition_pivot(t_stack	*a, t_stack	*b, int	pivot, int	size, t_log	*log)
{
	int	i;
	int	*push_count;

	push_count = (int *)malloc(sizeof(int) * 2);
	if (!push_count)
		return (NULL);
	i = 0;
	if (size == -1)
		size = a->top + 1;
	while (i < size)
	{
		if (a->array[a->top] < pivot)
		{
			pb(b, a, log);
			push_count[0]++;
		}
		else
		{
			ra(a, log);
			push_count[1]++;
		}
		i++;
	}
	return (push_count);
}

void	quick_sort(t_stack	*a, t_stack	*b, int	size, t_log	*log)
{
	int	pivot;
	int	*push_count;
	int	push_count_a;
	int	push_count_b;

	if (a->size <= 1)
		return;
	pivot = a->array[a->top];
	push_count = partition_pivot(a, b, pivot, size, log);
	if (!push_count)
		return;
	push_count_a = push_count[0];
	push_count_b = push_count[1];
	free(push_count);
	quick_sort(a, b, push_count_a, log);
	quick_sort(b, a, push_count_b, log);
	while (push_count_b--)
		pa(a, b, log);
}
