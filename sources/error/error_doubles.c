/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_doubles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:24:46 by eraad             #+#    #+#             */
/*   Updated: 2025/02/21 22:24:46 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//* Check if each element is unique, return 1 if it is not the case
int	error_doubles(int argc, int *array)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc - 1)
		{
			if (array[i] == array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
