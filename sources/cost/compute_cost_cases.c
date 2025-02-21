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
void	compute_cost_case_1(int	n_ra, int	n_rb, int	*cost)
{
	int	n_rr;

	n_rr = compute_n_rr(n_ra, n_rb);
	cost[0] = n_ra + n_rb - n_rr;
	cost[1] = n_ra - n_rr;
	cost[2] = n_rb - n_rr;
	cost[3] = n_rr;
	cost[4] = 0;
	cost[5] = 0;
	cost[6] = 0;
}

// ra + rrb
void	compute_cost_case_2(int	n_ra, int	n_rrb, int	*cost)
{
	cost[0] = n_ra + n_rrb;
	cost[1] = n_ra;
	cost[2] = 0;
	cost[3] = 0;
	cost[4] = 0;
	cost[5] = n_rrb;
	cost[6] = 0;
}

// rra + rb
void	compute_cost_case_3(int	n_rra, int	n_rb, int	*cost)
{
	cost[0] = n_rra + n_rb;
	cost[1] = 0;
	cost[2] = n_rb;
	cost[3] = 0;
	cost[4] = n_rra;
	cost[5] = 0;
	cost[6] = 0;
}

// rra + rrb - rrr and bias added to favor rrr
void	compute_cost_case_4(int	n_rra, int	n_rrb, int	*cost)
{
	int	n_rrr;

	n_rrr = compute_n_rr(n_rra, n_rrb);
	cost[0] = n_rra + n_rrb - n_rrr;
	cost[1] = 0;
	cost[2] = 0;
	cost[3] = 0;
	cost[4] = n_rra - n_rrr;
	cost[5] = n_rrb - n_rrr;
	cost[6] = n_rrr;
}
