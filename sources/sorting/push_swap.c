/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 21:04:29 by eraad             #+#    #+#             */
/*   Updated: 2025/02/20 21:04:29 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	evaluate_percentile(t_stack	*a, t_stack	*b, int percent_1, int	percent_2, t_percentiles	*best_percent)
{
	t_log	*temp_log;
	t_stack	*temp_a;
	t_stack	*temp_b;

	temp_a = copy_stack(a);
	temp_b = copy_stack(b);
	temp_log = init_log(10);
	dynamic_quick_sort(temp_a, temp_b, temp_log, percent_1, percent_2);
	sort_three(temp_a, temp_log);
	dynamic_insertion_sort(temp_a, temp_b, temp_log);
	sort_back_a(temp_a, temp_log);
	temp_log = check_log(temp_log);
	if (temp_log->index < best_percent->min_ops)
	{
		best_percent->min_ops = temp_log->index;
		best_percent->percentile_1 = percent_1;
		best_percent->percentile_2 = percent_2;
	}
	free_stack(temp_a);
	free_stack(temp_b);
	free_log(temp_log);
}


void	find_best_percentiles(t_stack	*a, t_stack	*b, int	*percentile_1, int	*percentile_2)
{
	t_percentiles	best_percents;
	int	percent_1;
	int	percent_2;

	best_percents.min_ops = INT_MAX;
	best_percents.percentile_1 = 5;
	best_percents.percentile_2 = 20;
	percent_1 = 5;
	while (percent_1 <=25)
	{
		percent_2 = 20;
		while (percent_2 <= 40)
		{
			evaluate_percentile(a, b, percent_1, percent_2, &best_percents);
			if (a->size > 400 && best_percents.min_ops < 5500)
				break;
			percent_2++;
		}
		percent_1++;
	}
	*percentile_1 = best_percents.percentile_1;
	*percentile_2 = best_percents.percentile_2;
}

void	push_swap(t_stack	*a, t_stack	*b, t_log	*log)
{
	int	percentile_1;
	int	percentile_2;

	if (a->size == 2)
		sa(a, log);
	else if (a->size == 3)
		sort_three(a, log);
	else
	{
		percentile_1 = 0;
		percentile_2 = 1;
		find_best_percentiles(a, b, &percentile_1, &percentile_2);
		dynamic_quick_sort(a, b, log, percentile_1, percentile_2);
		sort_three(a, log);
		dynamic_insertion_sort(a, b, log);
		sort_back_a(a, log);
	}
	free_stack(a);
	free_stack(b);
}
