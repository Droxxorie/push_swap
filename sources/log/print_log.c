/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:42:36 by eraad             #+#    #+#             */
/*   Updated: 2025/02/21 22:42:36 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//* Print the log to the standard output
void	print_log(t_log	*log)
{
	int	i;

	i = 0;
	while (i < log->index)
	{
		ft_putstr_fd(log->entries[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
	free_log(log);
}
