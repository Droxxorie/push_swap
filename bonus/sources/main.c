/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 23:42:41 by eraad             #+#    #+#             */
/*   Updated: 2025/02/21 23:42:41 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
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
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	checker(&a, &b, log);
	if (stack_is_sorted(&a))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free(a.array);
	free(b.array);
	free_log(log);
	return (1);
}
