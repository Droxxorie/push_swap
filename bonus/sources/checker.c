/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:10:22 by eraad             #+#    #+#             */
/*   Updated: 2025/02/21 15:10:22 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

// Check if the operation is valid return 1 if it is
static	int	check_operation(char *line)
{
	if (!ft_strcmp(line, "sa"))
		return (1);
	else if (!ft_strcmp(line, "sb"))
		return (1);
	else if (!ft_strcmp(line, "ss"))
		return (1);
	else if (!ft_strcmp(line, "pa"))
		return (1);
	else if (!ft_strcmp(line, "pb"))
		return (1);
	else if (!ft_strcmp(line, "ra"))
		return (1);
	else if (!ft_strcmp(line, "rb"))
		return (1);
	else if (!ft_strcmp(line, "rr"))
		return (1);
	else if (!ft_strcmp(line, "rra"))
		return (1);
	else if (!ft_strcmp(line, "rrb"))
		return (1);
	else if (!ft_strcmp(line, "rrr"))
		return (1);
	return (0);
}

// Apply the operation to the stack
static	void	apply_operation(t_stack	*a, t_stack	*b, t_log	*log,	char *op)
{
	if (!ft_strcmp(op, "sa"))
		sa(a, log);
	else if (!ft_strcmp(op, "sb"))
		sb(b, log);
	else if (!ft_strcmp(op, "ss"))
		ss(a, b, log);
	else if (!ft_strcmp(op, "pa"))
		pa(a, b, log);
	else if (!ft_strcmp(op, "pb"))
		pb(b, a, log);
	else if (!ft_strcmp(op, "ra"))
		ra(a, log);
	else if (!ft_strcmp(op, "rb"))
		rb(b, log);
	else if (!ft_strcmp(op, "rr"))
		rr(a, b, log);
	else if (!ft_strcmp(op, "rra"))
		rra(a, log);
	else if (!ft_strcmp(op, "rrb"))
		rrb(b, log);
	else if (!ft_strcmp(op, "rrr"))
		rrr(a, b, log);
}

static	void	small_parse(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			str[i] = '\0';
			return;
		}
		i++;
	}
}

// Check the operations and apply them
void	checker(t_stack	*a, t_stack	*b, t_log	*log)
{
	char	*line;

	line = get_next_line(0);
	if (!line)
		return;
	while (line)
	{
		small_parse(line);
		if (!check_operation(line))
		{
			free(line);
			ft_putstr_fd("Error\n", 2);
			return;
		}
		apply_operation(a, b, log, line);
		free(line);
		line = get_next_line(0);
	}
	free(line);
}


