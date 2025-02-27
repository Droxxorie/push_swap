/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:46:56 by eraad             #+#    #+#             */
/*   Updated: 2025/02/21 22:46:56 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

//* swap two pointers
static	void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

//* chunking of the array to sort
static	int	partition(int *array, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = array[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (array[j] < pivot)
			swap(&array[++i], &array[j]);
		j++;
	}
	swap(&array[i + 1], &array[high]);
	return (i + 1);
}

//* quick sort algo to sort the array
static	void	normalise_quick_sort(int *array, int low, int high)
{
	int	pivot;

	if (low < high)
	{
		pivot = partition(array, low, high);
		normalise_quick_sort(array, low, pivot - 1);
		normalise_quick_sort(array, pivot + 1, high);
	}
}

//* binary search algo to find the index of the element in the sorted array
static	int	binary_search(int *array, int size, int target)
{
	int	left;
	int	right;
	int	middle;

	left = 0;
	right = size - 1;
	while (left <= right)
	{
		middle = left + ((right - left) / 2);
		if (array[middle] == target)
			return (middle);
		else if (array[middle] < target)
			left = middle + 1;
		else
			right = middle - 1;
	}
	return (-1);
}

//* normalise the input as an array so we work only with unsigned integers
void	normalise(int *array, int size)
{
	int	*sorted_array;
	int	i;

	sorted_array = malloc(size * sizeof(int));
	if (!sorted_array)
		return ;
	i = -1;
	while (++i < size)
		sorted_array[i] = array[i];
	normalise_quick_sort(sorted_array, 0, size - 1);
	i = -1;
	while (++i < size)
	{
		array[i] = binary_search(sorted_array, size, array[i]);
		if (array[i] == -1)
			return ;
	}
	free(sorted_array);
}
