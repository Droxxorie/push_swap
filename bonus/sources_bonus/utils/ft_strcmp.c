/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:19:29 by eraad             #+#    #+#             */
/*   Updated: 2025/02/21 22:19:29 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

//* Compare two strings
int	ft_strcmp(const	char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
