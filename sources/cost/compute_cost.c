/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_cost.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 23:18:57 by eraad             #+#    #+#             */
/*   Updated: 2025/02/21 23:18:57 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	copy_cost(int *cost, int *temp)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		cost[i] = temp[i];
		i++;
	}
}

//* finds minimum case and returns it
static void	find_min_cost(int *n_ops, int *cost)
{
	int	cost_case_1[7];
	int	cost_case_2[7];
	int	cost_case_3[7];
	int	cost_case_4[7];

	compute_cost_case_1(n_ops[0], n_ops[1], cost_case_1);
	compute_cost_case_2(n_ops[0], n_ops[3], cost_case_2);
	compute_cost_case_3(n_ops[2], n_ops[1], cost_case_3);
	compute_cost_case_4(n_ops[2], n_ops[3], cost_case_4);
	copy_cost(cost, cost_case_1);
	if (cost_case_2[0] < cost[0])
		copy_cost(cost, cost_case_2);
	if (cost_case_3[0] < cost[0])
		copy_cost(cost, cost_case_3);
	if (cost_case_4[0] < cost[0])
		copy_cost(cost, cost_case_4);
	return ;
}

//* computes the cost of each case and returns the minimum cost
void	compute_cost(t_stack *a, t_stack *b, int i, int *cost)
{
	int	n_ra;
	int	n_rb;
	int	n_rra;
	int	n_rrb;
	int	n_ops[4];

	n_ra = compute_n_ra(a, b, i);
	n_rb = compute_n_rb(b, i);
	n_rra = compute_n_rra(a, b, i);
	n_rrb = compute_n_rrb(b, i);
	n_ops[0] = n_ra;
	n_ops[1] = n_rb;
	n_ops[2] = n_rra;
	n_ops[3] = n_rrb;
	find_min_cost(n_ops, cost);
	return ;
}
