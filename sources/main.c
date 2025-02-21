/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:00:00 by eraad             #+#    #+#             */
/*   Updated: 2025/02/15 14:00:00 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int	argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_log	*log;

	if (argc <= 2)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	initialize(argc, argv, &a, &b);
	log = init_log(10);
	if (!log || !a.array || !b.array)
	{
		ft_putstr_fd("Error\n", 1);
		return (0);
	}
	if (stack_is_sorted(&a))
		return (0);
	push_swap(&a, &b, log);
	log = check_log(log);
	print_log(log);
	return (1);
}
