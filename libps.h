#ifndef _LIBPS_H
# define _LIBPS_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct t_stack
{
	long int	*tab;
	int		len;
	int		nbr_mooves;
	int		max;
	int		min;
	struct t_stack *b;
}				s_stack;

typedef struct t_chunk
{
	int		cut;
	long int		max;
	int		min;
	int		n_med;
	int		n_max;
	int		n_min;
}				s_chunk;

void	clean_all(s_stack *a, s_stack *b);
int		is_double(long int *tab, int num, int i);
int		number_arg(char **arg);
int		len_num(char *arg);
int		swap_a(s_stack *a);
int		swap_b(s_stack *a, s_stack *b);
int		swap_both(s_stack *a, s_stack *b);
int		push_a(s_stack *a, s_stack *b);
int		push_b(s_stack *a, s_stack *b);
int		rotate_a(s_stack *a);
int		rotate_b(s_stack *a, s_stack *b);
int		rotate_both(s_stack *a, s_stack *b);
int		reverse_ra(s_stack *a);
int		reverse_rb(s_stack *a, s_stack *b);
int		reverse_rboth(s_stack *a, s_stack *b);
void	only_three(s_stack *a);
void	only_five(s_stack *a, s_stack *b);
void	only_hundred(s_stack *a, s_stack *b, s_chunk *chunk);
void	only_five_hundred(s_stack *a, s_stack *b, s_chunk *chunk);
void	find_max_min(s_stack *b);
void	sort_stack(s_stack *a, s_stack *b);
int		is_list_sorted(s_stack *a);
int		how_much_chunk(int len);
int		argv_errors(char **argv);
int		stack_a_err(long int *tab, int len);
void    print_stack(s_stack *a);

#endif