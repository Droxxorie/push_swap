/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_in_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 00:17:52 by eraad             #+#    #+#             */
/*   Updated: 2025/02/13 00:17:52 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

//transform and stock the input into an int array
int	*stock_in_array(int	argc, char **argv)
{
	int	i;
	int	*array;

	array = malloc((argc - 1) * sizeof(int));
	if (!array)
		return (NULL);
	i = 0;
	while (i < argc - 1)
	{
		
		array[i] = ft_atoi_long(argv[i + 1]);
		if (array[i] == 0 && argv[i + 1][0] != '0')
		{
			free(array);
			return (NULL);
		}
		i++;
	}
	return (array);
}
