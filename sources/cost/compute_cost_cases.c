/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_cost_cases.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:33:55 by eraad             #+#    #+#             */
/*   Updated: 2025/02/18 12:33:55 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// [cost, ra, rb, rr, rra, rrb, rrr]
// ra + rb - rr and bias added to favor rr
int	*compute_cost_case_1(int	n_ra, int	n_rb)
{
	int	cost_case1;
	int	*cost;
	int	n_rr;

	cost = malloc(sizeof(int) * 7);
	if (!cost)
		return (NULL);
	n_rr = compute_n_rr(n_ra, n_rb);
	cost_case1 = n_ra + n_rb - n_rr;
	cost[0] = cost_case1;
	cost[1] = n_ra - n_rr;
	cost[2] = n_rb - n_rr;
	cost[3] = n_rr;
	cost[4] = 0;
	cost[5] = 0;
	cost[6] = 0;
	return (cost); 
}

// ra + rrb
int	*compute_cost_case_2(int	n_ra, int	n_rrb)
{
	int	cost_case2;
	int	*cost;

	cost = malloc(sizeof(int) * 7);
	if (!cost)
		return (NULL);
	cost_case2 = n_ra + n_rrb;
	cost[0] = cost_case2;
	cost[1] = n_ra;
	cost[2] = 0;
	cost[3] = 0;
	cost[4] = 0;
	cost[5] = n_rrb;
	cost[6] = 0;
	return (cost);
}

// rra + rb
int	*compute_cost_case_3(int	n_rra, int	n_rb)
{
	int	cost_case3;
	int	*cost;

	cost = malloc(sizeof(int) * 7);
	if (!cost)
		return (NULL);
	cost_case3 = n_rra + n_rb;
	cost[0] = cost_case3;
	cost[1] = 0;
	cost[2] = n_rb;
	cost[3] = 0;
	cost[4] = n_rra;
	cost[5] = 0;
	cost[6] = 0;
	return (cost);
}

// rra + rrb - rrr and bias added to favor rrr
int	*compute_cost_case_4(int	n_rra, int	n_rrb)
{
	int	cost_case4;
	int	*cost;
	int	n_rrr;

	cost = malloc(sizeof(int) * 7);
	if (!cost)
		return (NULL);
	n_rrr = compute_n_rr(n_rra, n_rrb);
	cost_case4 = n_rra + n_rrb - n_rrr;
	cost[0] = cost_case4;
	cost[1] = 0;
	cost[2] = 0;
	cost[3] = 0;
	cost[4] = n_rra - n_rrr;
	cost[5] = n_rrb - n_rrr;
	cost[6] = n_rrr;
	return (cost);
}
