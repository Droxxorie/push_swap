/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:30:19 by eraad             #+#    #+#             */
/*   Updated: 2025/02/17 09:30:19 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// similar to np.arange in pyhton
int	*ft_arange(int start, int end, int step)
{
	int	*array;
	int	i;

	array = malloc(sizeof(int) * (end - start) / step);
	if (!array)
		return (NULL);
	i = 0;
	while (start < end)
	{
		array[i] = start;
		start += step;
		i++;
	}
	return (array);
}
