/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_limits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 00:32:41 by eraad             #+#    #+#             */
/*   Updated: 2025/02/13 00:32:41 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Check if < INT_MIN or > INT_MAX, return 1 if it is the case
int	error_limits(long i)
{
	if (i > INT_MAX || i < INT_MIN)
	{
		printf("Error limits\n");
		return (1);
	}
	return (0);
}
