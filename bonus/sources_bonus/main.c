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

//* Free all the allocated memory
static	void	free_all(t_stack *a, t_stack *b, t_log *log)
{
	if (a->array)
		free(a->array);
	if (b->array)
		free(b->array);
	if (log)
		free_log(log);
}

//* Initialize the stacks and the log
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
		free_all(&a, &b, log);
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (checker(&a, &b, log))
	{
		if (stack_is_sorted(&a) && stack_is_empty(&b))
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
	}
	free_all(&a, &b, log);
	return (1);
}
