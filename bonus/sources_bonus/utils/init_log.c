/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_log.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:41:15 by eraad             #+#    #+#             */
/*   Updated: 2025/02/21 22:41:15 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

//* Initialize the log
t_log	*init_log(int initial_capacity)
{
	t_log	*log;

	log = (t_log *)malloc(sizeof(t_log));
	if (!log)
		return (NULL);
	log->entries = (char **)malloc(sizeof(char *) * initial_capacity);
	if (!log->entries)
	{
		free(log);
		return (NULL);
	}
	log->index = 0;
	log->capacity = initial_capacity;
	return (log);
}
