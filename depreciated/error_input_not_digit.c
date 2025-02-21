/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_input_not_digit.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:45:58 by eraad             #+#    #+#             */
/*   Updated: 2025/02/21 22:45:58 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Check if an elements of argv is digits
// return 1 if it find an error and 1 otherwise
int	error_input_not_digit(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '+') || (str[i] == '-'))
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			i++;
		else
			return (1);
	}
	return (0);
}
