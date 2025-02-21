/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:58:47 by eraad             #+#    #+#             */
/*   Updated: 2025/02/21 22:58:47 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// [cost, ra, rb, rr, rra, rrb, rrr]
// apply the minimum cost operation
void	do_op(t_stack	*a, t_stack	*b, t_log	*log, int	*cost)
{
	int	cost_temp[7];
	int	i;

	i = 0;
	while (i < 7)
	{
		cost_temp[i] = cost[i];
		i++;
	}
	while (cost_temp[3]-- > 0)
		rr(a, b, log);
	while (cost_temp[1]-- > 0)
		ra(a, log);
	while (cost_temp[2]-- > 0)
		rb(b, log);
	while (cost_temp[6]-- > 0)
		rrr(a, b, log);
	while (cost_temp[4]-- > 0)
		rra(a, log);
	while (cost_temp[5]-- > 0)
		rrb(b, log);
	pa(a, b, log);
}
