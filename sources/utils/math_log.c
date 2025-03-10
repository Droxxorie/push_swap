/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_log.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 11:16:02 by eraad             #+#    #+#             */
/*   Updated: 2025/02/23 11:16:02 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//* Return the log base 2 of n
int	log_2_n(unsigned int n)
{
	unsigned int	log;

	log = 0;
	while (n > 1)
	{
		n /= 2;
		log++;
	}
	return (log);
}
