/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 23:43:28 by eraad             #+#    #+#             */
/*   Updated: 2025/02/21 23:43:28 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

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

// Stack
void	free_stack(t_stack *stack);
int		stack_is_full(t_stack *stack);
int		stack_is_empty(t_stack *stack);
int		stack_is_sorted(t_stack *stack);
void	init_stack(t_stack *stack, int size);

// Errors
int		error_doubles(int argc, int *array);

// Parsing
long	ft_atoi_long(const char *nptr);
void	normalise(int *array, int size);
int		*stock_in_array(int argc, char **argv);

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

//Utils
void	free_log(t_log *log);
char	*get_next_line(int fd);
char	*ft_leftover(char *str);
char	*ft_strdup(const char *s);
char	*ft_clean_line(char *str);
size_t	ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
t_log	*init_log(int initial_capacity);
char	*ft_read_str(int fd, char *str);
char	*ft_strrchr(const char *s, int c);
int		ft_strcmp(const	char *s1, const char *s2);
void	log_operations(t_log *log, char *operation);
char	*ft_strjoin(char const *s1, char const *s2);
void	checker(t_stack	*a, t_stack	*b, t_log	*log);
void	initialize(int argc, char **argv, t_stack *a, t_stack *b);

#endif
