/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fill_stack_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 20:31:13 by eraad             #+#    #+#             */
/*   Updated: 2025/02/13 20:31:13 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Fill the stack a with the provided array
int	fill_stack_a(t_stack *stacks, int *array, int size)
{
	t_list	*new;
	int		*data;
	int		i;

	i = 0;
	while (i < size)
	{
		data = malloc(sizeof(int));
		if (!data)
		{
			ft_lstclear(&stacks->a, free);
			return (0);
		}
		*data = array[i];
		new = ft_lstnew(data);
		if (!new)
		{
			free(data);
			ft_lstclear(&stacks->a, free);
			return (0);
		}
		ft_lstadd_back(&stacks->a, new);
		i++;
	}
	return (1);
}
