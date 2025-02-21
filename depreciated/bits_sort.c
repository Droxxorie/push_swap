/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:21:37 by eraad             #+#    #+#             */
/*   Updated: 2025/02/17 16:21:37 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	bits_sort_base_2(t_stack	*a, t_stack	*b, t_log	*log, int	bit)
{
	int	j;

	j = a->size - a->top;
	while (j > 0)
	{
		if ((a->array[a->top] >> (bit * 1) & 1) == 0)
			pb(b, a, log);
		else
			ra(a, log);
		j--;
	}
}

static	void	bits_sort_base_4(t_stack	*a, t_stack	*b, t_log	*log, int	bit)
{
	int	j;

	j = a->size - a->top;
	while (j > 0)
	{
		if ((a->array[a->top] >> (bit * 2) & 3) == 0)
			pb(b, a, log);
		else
			ra(a, log);
		j--;
	}
}

static	void	bits_sort_base_8(t_stack	*a, t_stack	*b, t_log	*log, int	bit)
{
	int	j;

	j = a->size - a->top;
	while (j > 0)
	{
		if ((a->array[a->top] >> (bit * 3) & 7) == 0)
			pb(b, a, log);
		else
			ra(a, log);
		j--;
	}
}

void	bits_sort(t_stack	*a, t_stack	*b, t_log	*log, int	base, int	bit)
{
	if (base)
		bits_sort_base_2(a, b, log, bit);
	else if (base == 4)
		bits_sort_base_4(a, b, log, bit);
	else
		bits_sort_base_8(a, b ,log, bit);
}
