/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:19:54 by eraad             #+#    #+#             */
/*   Updated: 2025/02/21 22:19:54 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//* Evaluate if the current percentiles are the best 
//* and update the best percentiles if they are
void	eval_percent(t_stack	*a, t_stack	*b, int *p, t_pct	*best_p)
{
	t_log	*temp_log;
	t_stack	*temp_a;
	t_stack	*temp_b;

	temp_a = copy_stack(a);
	temp_b = copy_stack(b);
	temp_log = init_log(10);
	dynamic_quick_sort(temp_a, temp_b, temp_log, p);
	sort_three(temp_a, temp_log);
	dynamic_insertion_sort(temp_a, temp_b, temp_log);
	sort_back_a(temp_a, temp_log);
	temp_log = check_log(temp_log);
	if (temp_log->index < best_p->min_ops)
	{
		best_p->min_ops = temp_log->index;
		best_p->percentile_1 = p[0];
		best_p->percentile_2 = p[1];
	}
	free_stack(temp_a);
	free_stack(temp_b);
	free_log(temp_log);
}

//* Find the best percentiles for the dynamic quick sort algorithm
//* by iterating over the percentiles and evaluating the number of operations
void	find_best_percentiles(t_stack	*a, t_stack	*b, int	*p)
{
	t_pct	best_percents;
	int		percent[2];
	int		n;

	best_percents.min_ops = INT_MAX;
	best_percents.percentile_1 = 5;
	best_percents.percentile_2 = 20;
	percent[0] = 5;
	n = a->size;
	while (percent[0] <= 25)
	{
		percent[1] = 20;
		while (percent[1] <= 40)
		{
			eval_percent(a, b, percent, &best_percents);
			if (n > 100 && best_percents.min_ops < (n * (3 + log_2_n(n))))
				break ;
			percent[1]++;
		}
		percent[0]++;
	}
	p[0] = best_percents.percentile_1;
	p[1] = best_percents.percentile_2;
}

//* Sort the stack a using the push_swap algorithm
//* by first finding the best percentiles for the dynamic quick sort
//* then sorting the stack using the dynamic quick sort
//* then sorting the stack using the dynamic insertion sort
//* then sorting the stack back to the original order
//* then checking the log for redundant or unnecessary operations
//* and finally printing the operations
void	push_swap(t_stack	*a, t_stack	*b, t_log	*log)
{
	int	percentiles[2];

	if (a->size == 2)
		sa(a, log);
	else if (a->size == 3)
		sort_three(a, log);
	else
	{
		percentiles[0] = 0;
		percentiles[1] = 1;
		find_best_percentiles(a, b, percentiles);
		dynamic_quick_sort(a, b, log, percentiles);
		sort_three(a, log);
		dynamic_insertion_sort(a, b, log);
		sort_back_a(a, log);
	}
}
