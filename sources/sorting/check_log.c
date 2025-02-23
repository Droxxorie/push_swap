/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:50:19 by eraad             #+#    #+#             */
/*   Updated: 2025/02/21 22:50:19 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Check the log, return 1 if nothing is to discard
static	int	first_log_check(t_log	*log, int i)
{
	if ((!ft_strcmp(log->entries[i], "ra")
			&& !ft_strcmp(log->entries[i + 1], "rra"))
		|| (!ft_strcmp(log->entries[i], "rra")
			&& !ft_strcmp(log->entries[i + 1], "ra")))
		return (1);
	if ((!ft_strcmp(log->entries[i], "rb")
			&& !ft_strcmp(log->entries[i + 1], "rrb"))
		|| (!ft_strcmp(log->entries[i], "rrb")
			&& !ft_strcmp(log->entries[i + 1], "rb")))
		return (1);
	if ((!ft_strcmp(log->entries[i], "sa")
			&& !ft_strcmp(log->entries[i + 1], "sb"))
		|| (!ft_strcmp(log->entries[i], "sb")
			&& !ft_strcmp(log->entries[i + 1], "sa")))
		return (1);
	if ((!ft_strcmp(log->entries[i], "pa")
			&& !ft_strcmp(log->entries[i + 1], "pb"))
		|| (!ft_strcmp(log->entries[i], "pb")
			&& !ft_strcmp(log->entries[i + 1], "pa")))
		return (1);
	return (0);
}

// Check the log, return 1 if an operation as been changed
static	int	second_log_check(t_log	*log, t_log	*new_log, int i)
{
	if ((!ft_strcmp(log->entries[i], "ra")
			&& !ft_strcmp(log->entries[i + 1], "rb"))
		|| (!ft_strcmp(log->entries[i], "rb")
			&& !ft_strcmp(log->entries[i + 1], "ra")))
	{
		log_operations(new_log, "rr");
		return (1);
	}
	else if ((!ft_strcmp(log->entries[i], "rra")
			&& !ft_strcmp(log->entries[i + 1], "rrb"))
		|| (!ft_strcmp(log->entries[i], "rrb")
			&& !ft_strcmp(log->entries[i + 1], "rra")))
	{
		log_operations(new_log, "rrr");
		return (1);
	}
	else if ((!ft_strcmp(log->entries[i], "sa")
			&& !ft_strcmp(log->entries[i + 1], "sb"))
		|| (!ft_strcmp(log->entries[i], "sb")
			&& !ft_strcmp(log->entries[i + 1], "sa")))
	{
		log_operations(new_log, "ss");
		return (1);
	}
	return (0);
}

// Check the log, return 1 if an operation as been changed
static	int	third_log_check(t_log	*log, t_log	*new_log, int i)
{
	if ((i < log->index - 2) && (!ft_strcmp(log->entries[i], "ra")
			&& !ft_strcmp(log->entries[i + 1], "pb")
			&& !ft_strcmp(log->entries[i + 2], "rra")))
	{
		log_operations(new_log, "sa");
		log_operations(new_log, "pb");
		return (1);
	}
	else if ((i < log->index - 2)
		&& !ft_strcmp(log->entries[i], "rb")
		&& !ft_strcmp(log->entries[i + 1], "pa")
		&& !ft_strcmp(log->entries[i + 2], "rrb"))
	{
		log_operations(new_log, "sb");
		log_operations(new_log, "pa");
		return (1);
	}
	return (0);
}

t_log	*check_log(t_log	*log)
{
	t_log	*new_log;
	int		i;

	new_log = init_log(10);
	if (!new_log)
		return (NULL);
	i = 0;
	while (i < log->index - 1)
	{
		if (first_log_check(log, i) == 1)
			i += 2;
		else if (second_log_check(log, new_log, i) == 1)
			i += 2;
		else if (third_log_check(log, new_log, i) == 1)
			i += 3;
		else
		{
			log_operations(new_log, log->entries[i]);
			i++;
		}
	}
	if (i == log->index - 1)
		log_operations(new_log, log->entries[i]);
	free_log(log);
	return (new_log);
}
