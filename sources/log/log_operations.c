/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 22:55:27 by eraad             #+#    #+#             */
/*   Updated: 2025/02/20 22:55:27 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	expend_log(t_log *log)
{
	int		new_capacity;
	char	**new_entries;
	int		i;

	new_capacity = log->capacity + 10;
	new_entries = (char **)malloc(sizeof(char *) * new_capacity);
	if(!new_entries)
		return;
	i = 0;
	while (i < log->index)
	{
		new_entries[i] = log->entries[i];
		i++;
	}
	free(log->entries);
	log->entries = new_entries;
	log->capacity = new_capacity;
}

void	log_operations(t_log	*log, char	*operation)
{
	if (log->index >= log->capacity)
		expend_log(log);	
	log->entries[log->index] = ft_strdup(operation);
	log->index++;
}
