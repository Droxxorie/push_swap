#ifndef CHECKER_H
# define CHECKER_H

#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

typedef	struct	s_stack
{
	int *array;
	int	top;
	int	size;
}	t_stack;

typedef	struct	s_log
{
	char **entries;
	int	index;
	int	capacity;
}	t_log;

// Stack
int		stack_is_empty(t_stack	*stack);
int		stack_is_full(t_stack	*stack);
int		stack_is_sorted(t_stack	*stack);
void	free_stack(t_stack	*stack);
void	init_stack(t_stack *stack, int	size);
t_stack	*copy_stack(t_stack	*stack);

// Errors
int		error_input_not_digit(char *str);
int		error_doubles(int	argc, int	*array);

// Parsing
long	ft_atoi_long(const char *nptr);
int		*stock_in_array(int	argc, char **argv);
void	normalise(int	*array, int	size);

// Operations
void	sa(t_stack	*a, t_log	*log);
void	sb(t_stack	*b, t_log	*log);
void	ss(t_stack	*a, t_stack	*b, t_log	*log);
void	pa(t_stack	*a, t_stack	*b, t_log	*log);
void	pb(t_stack	*b, t_stack	*a, t_log	*log);
void	ra(t_stack	*a, t_log	*log);
void	rb(t_stack	*b, t_log	*log);
void	rr(t_stack	*a, t_stack	*b, t_log	*log);
void	rra(t_stack	*a, t_log	*log);
void	rrb(t_stack	*b, t_log	*log);
void	rrr(t_stack	*a, t_stack	*b, t_log	*log);

//Utils
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
char	*ft_strdup(const char *s);
int		find_min_index(t_stack	*stack);
int		find_max_index(t_stack	*stack);
int		ft_isdigit(int c);

void	*ft_memcpy(void *dest, const void *src, size_t n);


char	*get_next_line(int fd);
char	*ft_read_str(int fd, char *str);
char	*ft_clean_line(char *str);
char	*ft_leftover(char *str);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
char	*ft_strrchr(const char *s, int c);


void	checker(t_stack	*a, t_stack	*b, t_log	*log);
void	initialize(int	argc, char **argv, t_stack *a, t_stack *b);
void	free_log(t_log	*log);
t_log	*init_log(int	initial_capacity);
void	log_operations(t_log	*log, char	*operation);
int	ft_strcmp(const	char *s1, const char *s2);


#endif