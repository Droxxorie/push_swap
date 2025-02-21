/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:38:43 by eraad             #+#    #+#             */
/*   Updated: 2025/02/13 15:38:43 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

// Sort an array using bubble sort -> the function is used to normalise the array
void	*bubble_sort(int	*array_to_sort, int	size)
{
	int	temp;
	int	swapped;
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		swapped = 0;
		j = 0;
		while (j < size - i - 1)
		{
			if (array_to_sort[j] > array_to_sort[j + 1])
			{
				temp = array[j];
				array_to_sort[j] = array_to_sort[j + 1];
				array_to_sort[j + 1] = temp;
				swapped = 1;
			}
			j++;
		}
		if (!swapped)
			break;
		i++;
	}
}
