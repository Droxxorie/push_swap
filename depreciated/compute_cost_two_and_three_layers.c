/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_cost_two_and_three_layers.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:08:04 by eraad             #+#    #+#             */
/*   Updated: 2025/02/20 16:08:04 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Not as efficient as the original implementation
void	fill_cost_two_layers(int	*cost, int	*first_move_cost, int	*second_move_cost)
{
	int	i;
	
	i = 0;
	cost[0] = first_move_cost[0] + second_move_cost[0];
	while (i++ < 7)
		cost[i] = first_move_cost[i];
}

// Computes the cost of two layers
int	*compute_cost_two_layers(t_stack	*a, t_stack	*b, int	i)
{
	int	*first_move_cost;
	int	*second_move_cost;
	int	*total_cost;
	t_stack	*a_copy;
	t_stack	*b_copy;
	t_log *dump;

	dump = init_log(10);
	if (!dump)
		return (NULL);
	first_move_cost = compute_cost(a, b, i);
	if (!first_move_cost)
	{
		free_log(dump);
		return (NULL);
	}
	a_copy = copy_stack(a);
	b_copy = copy_stack(b);
	if (!a_copy || !b_copy)
	{
		free(first_move_cost);
		free_stack(a_copy);
		free_stack(b_copy);
		free_log(dump);
		return (NULL);
	}
	do_op(a_copy, b_copy, dump, first_move_cost);
	second_move_cost = compute_cost(a_copy, b_copy, b_copy->top);
	if (!second_move_cost)
	{
		free(first_move_cost);
		free_stack(a_copy);
		free_stack(b_copy);
		free_log(dump);
		return (NULL);
	}
	total_cost = malloc(sizeof(int) * 7);
	if (!total_cost)
	{
		free(first_move_cost);
		free(second_move_cost);
		free_stack(a_copy);
		free_stack(b_copy);
		free_log(dump);
		return (NULL);
	}
	fill_cost_two_layers(total_cost, first_move_cost, second_move_cost);
	free(first_move_cost);
	free(second_move_cost);
	free_stack(a_copy);
	free_stack(b_copy);
	free_log(dump);
	return (total_cost);
}

static	void	fill_cost_three_layers(int *cost, int *first_move_cost, int *second_move_cost, int *third_move_cost)
{
	int	i;

	i = 0;
	cost[0] = first_move_cost[0] + second_move_cost[0] + third_move_cost[0];
	while (i++ < 7)
		cost[i] = first_move_cost[i];
}

int	*compute_cost_three_layers(t_stack *a, t_stack *b, int i)
{
	int	*first_move_cost;
	int	*second_move_cost;
	int	*third_move_cost;
	int	*total_cost;
	t_stack	*a_copy1, *b_copy1;
	t_stack	*a_copy2, *b_copy2;
	t_log	*dump;

	dump = init_log(10);
	if (!dump)
		return (NULL);
	first_move_cost = compute_cost(a, b, i);
	if (!first_move_cost)
	{
		free_log(dump);
		return (NULL);
	}
	a_copy1 = copy_stack(a);
	b_copy1 = copy_stack(b);
	if (!a_copy1 || !b_copy1)
	{
		free(first_move_cost);
		free_stack(a_copy1);
		free_stack(b_copy1);
		free_log(dump);
		return (NULL);
	}
	do_op(a_copy1, b_copy1, dump, first_move_cost);
	second_move_cost = compute_cost(a_copy1, b_copy1, b_copy1->top);
	if (!second_move_cost)
	{
		free(first_move_cost);
		free_stack(a_copy1);
		free_stack(b_copy1);
		free_log(dump);
		return (NULL);
	}
	a_copy2 = copy_stack(a_copy1);
	b_copy2 = copy_stack(b_copy1);
	if (!a_copy2 || !b_copy2)
	{
		free(first_move_cost);
		free(second_move_cost);
		free_stack(a_copy1);
		free_stack(b_copy1);
		free_stack(a_copy2);
		free_stack(b_copy2);
		free_log(dump);
		return (NULL);
	}
	do_op(a_copy2, b_copy2, dump, second_move_cost);
	third_move_cost = compute_cost(a_copy2, b_copy2, b_copy2->top);
	if (!third_move_cost)
	{
		free(first_move_cost);
		free(second_move_cost);
		free_stack(a_copy1);
		free_stack(b_copy1);
		free_stack(a_copy2);
		free_stack(b_copy2);
		free_log(dump);
		return (NULL);
	}
	total_cost = malloc(sizeof(int) * 7);
	if (!total_cost)
	{
		free(first_move_cost);
		free(second_move_cost);
		free(third_move_cost);
		free_stack(a_copy1);
		free_stack(b_copy1);
		free_stack(a_copy2);
		free_stack(b_copy2);
		free_log(dump);
		return (NULL);
	}
	fill_cost_three_layers(total_cost, first_move_cost, second_move_cost, third_move_cost);
	free(first_move_cost);
	free(second_move_cost);
	free(third_move_cost);
	free_stack(a_copy1);
	free_stack(b_copy1);
	free_stack(a_copy2);
	free_stack(b_copy2);
	free_log(dump);
	return (total_cost);
}
