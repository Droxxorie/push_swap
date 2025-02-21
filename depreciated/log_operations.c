/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:59:43 by eraad             #+#    #+#             */
/*   Updated: 2025/02/14 16:59:43 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Realloc memory for the operations log
static	void	expand_log(char ***operations_log, int	*log_index, int	log_capacity)
{
	int		new_capacity;
	char	**new_log;
	int		i;

	new_capacity = *log_capacity * 2;
	new_log = (char **)malloc(sizeof(char *) * new_capacity);
	if (!new_log)
		return;
	i = 0;
	while (i < *log_index)
	{
		new_log[i] = (*operations_log)[i];
		i++;
	}
	free(*operations_log);
	*operations_log = new_log;
	*log_capacity = new_capacity;
}

// Log the operation
void	log_opperation(char ***operations_log, int	*log_index, char *operation, int	*log_capacity)
{
	if (*log_index >= log_capacity)
		expand_log(operations_log, log_index, log_capacity);
	(*operations_log)[*log_index] = ft_strdup(operation);
	(*log_index)++;
}
