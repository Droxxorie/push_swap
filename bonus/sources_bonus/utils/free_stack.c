/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:20:50 by eraad             #+#    #+#             */
/*   Updated: 2025/02/21 22:20:50 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

//* Free the stack
void	free_stack(t_stack	*stack)
{
	if (!stack || !stack->array)
		return ;
	free(stack->array);
	free(stack);
}
