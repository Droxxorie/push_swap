/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_log.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:40:32 by eraad             #+#    #+#             */
/*   Updated: 2025/02/21 22:40:32 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//* Free the log
void	free_log(t_log	*log)
{
	int	i;

	i = 0;
	while (i < log->index)
		free(log->entries[i++]);
	free(log->entries);
	free(log);
}
