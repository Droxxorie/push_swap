/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 23:42:35 by eraad             #+#    #+#             */
/*   Updated: 2025/02/21 23:42:35 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

//* Check if the operation is valid return 1 if it is, 0 if not
static	int	check_operation(char *line)
{
	if (!ft_strcmp(line, "sa\n"))
		return (1);
	else if (!ft_strcmp(line, "sb\n"))
		return (1);
	else if (!ft_strcmp(line, "ss\n"))
		return (1);
	else if (!ft_strcmp(line, "pa\n"))
		return (1);
	else if (!ft_strcmp(line, "pb\n"))
		return (1);
	else if (!ft_strcmp(line, "ra\n"))
		return (1);
	else if (!ft_strcmp(line, "rb\n"))
		return (1);
	else if (!ft_strcmp(line, "rr\n"))
		return (1);
	else if (!ft_strcmp(line, "rra\n"))
		return (1);
	else if (!ft_strcmp(line, "rrb\n"))
		return (1);
	else if (!ft_strcmp(line, "rrr\n"))
		return (1);
	return (0);
}

//* Apply the operation to the stack
static void	apply_operation(t_stack *a, t_stack *b, t_log *log, char *op)
{
	if (!ft_strcmp(op, "sa\n"))
		sa(a, log);
	else if (!ft_strcmp(op, "sb\n"))
		sb(b, log);
	else if (!ft_strcmp(op, "ss\n"))
		ss(a, b, log);
	else if (!ft_strcmp(op, "pa\n"))
		pa(a, b, log);
	else if (!ft_strcmp(op, "pb\n"))
		pb(b, a, log);
	else if (!ft_strcmp(op, "ra\n"))
		ra(a, log);
	else if (!ft_strcmp(op, "rb\n"))
		rb(b, log);
	else if (!ft_strcmp(op, "rr\n"))
		rr(a, b, log);
	else if (!ft_strcmp(op, "rra\n"))
		rra(a, log);
	else if (!ft_strcmp(op, "rrb\n"))
		rrb(b, log);
	else if (!ft_strcmp(op, "rrr\n"))
		rrr(a, b, log);
}

//* Check the operations and apply them
//* return 1 if all the operations are valid
int	checker(t_stack	*a, t_stack	*b, t_log	*log)
{
	char	*line;

	if (stack_is_sorted(a))
		return (0);
	line = get_next_line(0);
	if (!line)
		return (0);
	while (line)
	{
		if (!check_operation(line))
		{
			free(line);
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		apply_operation(a, b, log, line);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	return (1);
}
