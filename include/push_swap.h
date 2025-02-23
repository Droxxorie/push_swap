/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 22:54:54 by eraad             #+#    #+#             */
/*   Updated: 2025/02/12 22:54:54 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

// Structs
typedef struct s_stack
{
	int	*array;
	int	top;
	int	size;
}	t_stack;

typedef struct s_log
{
	char	**entries;
	int		index;
	int		capacity;
}	t_log;

typedef struct s_percentiles
{
	int	min_ops;
	int	percentile_1;
	int	percentile_2;
}	t_pct;

//Utils
int		ft_isdigit(int c);
char	*ft_strdup(const char *s);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
int		find_min_index(t_stack	*stack);
int		find_max_index(t_stack	*stack);
int		ft_strcmp(const	char *s1, const char *s2);
void	*ft_memcpy(void *dest, const void *src, size_t n);

// Stack
void	free_stack(t_stack	*stack);
t_stack	*copy_stack(t_stack	*stack);
int		stack_is_empty(t_stack	*stack);
int		stack_is_full(t_stack	*stack);
int		stack_is_sorted(t_stack	*stack);
void	init_stack(t_stack *stack, int size);
int		log_2_n(unsigned int n);

// Errors
int		error_doubles(int argc, int *array);

// Parsing
long	ft_atoi_long(const char *nptr);
void	normalise(int *array, int size);

// Initialisation
void	initialize(int argc, char **argv, t_stack *a, t_stack *b);

// Logging
void	free_log(t_log *log);
void	print_log(t_log *log);
t_log	*init_log(int initial_capacity);
void	log_operations(t_log	*log, char	*operation);

// Operations
void	sa(t_stack	*a, t_log	*log);
void	sb(t_stack	*b, t_log	*log);
void	ra(t_stack	*a, t_log	*log);
void	rb(t_stack	*b, t_log	*log);
void	rra(t_stack	*a, t_log	*log);
void	rrb(t_stack	*b, t_log	*log);
void	pa(t_stack	*a, t_stack	*b, t_log	*log);
void	pb(t_stack	*b, t_stack	*a, t_log	*log);
void	ss(t_stack	*a, t_stack	*b, t_log	*log);
void	rr(t_stack	*a, t_stack	*b, t_log	*log);
void	rrr(t_stack	*a, t_stack	*b, t_log	*log);

// Cost
int		compute_n_rb(t_stack *b, int i);
int		compute_n_rrb(t_stack *b, int i);
int		compute_n_rr(int n_ra, int n_rb);
int		compute_n_rrr(int n_rra, int n_rrb);
int		compute_n_ra(t_stack *a, t_stack *b, int i);
int		compute_n_rra(t_stack *a, t_stack *b, int i);
void	compute_cost_case_1(int n_ra, int n_rb, int *cost);
void	compute_cost_case_2(int n_ra, int n_rrb, int *cost);
void	compute_cost_case_3(int n_rra, int n_rb, int *cost);
void	compute_cost_case_4(int n_rra, int n_rrb, int *cost);
void	compute_cost(t_stack *a, t_stack *b, int i, int *cost);

// Sorting
t_log	*check_log(t_log *log);
void	sort_three(t_stack *a, t_log *log);
void	sort_back_a(t_stack *a, t_log *log);
void	push_swap(t_stack *a, t_stack *b, t_log *log);
void	do_op(t_stack *a, t_stack *b, t_log *log, int *cost);
void	dynamic_insertion_sort(t_stack *a, t_stack *b, t_log *log);
void	dynamic_quick_sort(t_stack *a, t_stack *b, t_log *log, int *p);

#endif