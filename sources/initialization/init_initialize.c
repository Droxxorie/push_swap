/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_initialize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:38:32 by eraad             #+#    #+#             */
/*   Updated: 2025/02/21 22:38:32 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//* Check if the number is zero
static	int	is_zero(char	*str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if ((str[i] == '+' || str[i] == '-') && str[i + 1])
		i++;
	while (str[i])
	{
		if (str[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

//* Create an array from the input
static	int	*create_array(int argc, char **argv)
{
	int	i;
	int	*array;

	array = malloc((argc - 1) * sizeof(int));
	if (!array)
		return (NULL);
	i = 0;
	while (i < argc - 1)
	{
		if (argv[i + 1][0] == '\0')
		{
			free(array);
			return (NULL);
		}
		array[i] = ft_atoi_long(argv[i + 1]);
		if (array[i] == 0 && !is_zero(argv[i + 1]))
		{
			free(array);
			return (NULL);
		}
		i++;
	}
	return (array);
}

//* Initialize the stacks, creat an array from input, check errors
//* normalise the array and fill stack a, return the stacks
static	int	*init_1(int argc, char	**argv)
{
	int	*array;
	int	i;

	array = create_array(argc, argv);
	if (!array)
		return (NULL);
	if (error_doubles(argc, array))
	{
		free(array);
		return (NULL);
	}
	normalise(array, argc - 1);
	i = 0;
	while (i < argc - 1)
	{
		if (array[i] == -1)
		{
			free(array);
			return (NULL);
		}
		i++;
	}
	return (array);
}

//* Stock the array in the stack
static	void	stock_in_stack(t_stack	*stack, int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		stack->array[i] = array[i];
		i++;
	}
	free(array);
}

//* Initialize the stacks, creat an array from input, check errors
//* normalise the array and fill stack a, return the stacks
void	initialize(int argc, char **argv, t_stack *a, t_stack *b)
{
	int	*array;

	array = init_1(argc, argv);
	if (!array)
	{
		a->array = NULL;
		b->array = NULL;
		return ;
	}
	init_stack(a, argc - 1);
	init_stack(b, argc - 1);
	if (!a->array || !b->array)
	{
		a->array = NULL;
		b->array = NULL;
		free(array);
		return ;
	}
	stock_in_stack(a, array, argc - 1);
	a->top = 0;
	return ;
}
