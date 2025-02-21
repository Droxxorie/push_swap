/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_cost.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:36:31 by eraad             #+#    #+#             */
/*   Updated: 2025/02/18 12:36:31 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	free_cost_cases(int	*min_cost, int	*cost_case_1, int	*cost_case_2, int	*cost_case_3, int	*cost_case_4)
{
	if (min_cost != cost_case_1)
		free(cost_case_1);
	if (min_cost != cost_case_2)
		free(cost_case_2);
	if (min_cost != cost_case_3)
		free(cost_case_3);
	if (min_cost != cost_case_4)
		free(cost_case_4);
}
// finds minimum case and returns it
static	int	*find_min_cost(int	n_ra, int	n_rb, int n_rra, int n_rrb)
{
	int	*cost_case_1;
	int	*cost_case_2;
	int	*cost_case_3;
	int	*cost_case_4;
	int *min_cost;

	cost_case_1 = compute_cost_case_1(n_ra, n_rb);
	cost_case_2 = compute_cost_case_2(n_ra, n_rrb);
	cost_case_3 = compute_cost_case_3(n_rra, n_rb);
	cost_case_4 = compute_cost_case_4(n_rra, n_rrb);
	min_cost = cost_case_1;
	if (cost_case_2[0] < min_cost[0])
		min_cost = cost_case_2;
	if (cost_case_3[0] < min_cost[0])
		min_cost = cost_case_3;
	if (cost_case_4[0] < min_cost[0])
		min_cost = cost_case_4;
	free_cost_cases(min_cost, cost_case_1, cost_case_2, cost_case_3, cost_case_4);
	return (min_cost);
}

// computes the cost of each case and returns the minimum cost
int	*compute_cost(t_stack *a, t_stack *b, int	i)
{
	int	n_ra;
	int	n_rb;
	int	n_rra;
	int	n_rrb;
	int	*cost;

	n_ra = compute_n_ra(a, b, i);
	n_rb = compute_n_rb(b, i);
	n_rra = compute_n_rra(a, b, i);
	n_rrb = compute_n_rrb(b, i);
	cost = find_min_cost(n_ra, n_rb, n_rra, n_rrb);
	return (cost);
}
