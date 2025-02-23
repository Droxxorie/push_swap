/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:20:01 by eraad             #+#    #+#             */
/*   Updated: 2025/02/21 22:20:01 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	free_all(t_stack *a, t_stack *b, t_log *log)
{
	if (a->array)
		free(a->array);
	if (b->array)
		free(b->array);
	if (log)
		free_log(log);
}

int	main(int argc, char	**argv)
{
	t_stack	a;
	t_stack	b;
	t_log	*log;

	if (argc < 2)
		return (0);
	initialize(argc, argv, &a, &b);
	log = init_log(10);
	if (!log || !a.array || !b.array)
	{
		free_all(&a, &b, log);
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (stack_is_sorted(&a))
	{
		free_all(&a, &b, log);
		return (0);
	}
	push_swap(&a, &b, log);
	log = check_log(log);
	print_log(log);
	free(a.array);
	free(b.array);
	return (1);
}
