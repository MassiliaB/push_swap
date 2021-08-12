#ifndef _LIBPS_H
# define _LIBPS_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stack
{
	long int		*tab;
	int				len;
	int				nbr_mooves;
	int				max;
	int				min;
	struct t_stack	*b;
}				t_stack;

typedef struct s_chunk
{
	int			cut;
	long int	max;
	int			min;
	int			n_med;
	int			n_max;
	int			n_min;
}				t_chunk;

void	clean_all(t_stack *a, t_stack *b);
int		is_double(long int *tab, int num, int i);
int		number_arg(char **arg);
int		len_num(char *arg);
int		swap_a(t_stack *a);
int		swap_b(t_stack *a, t_stack *b);
int		swap_both(t_stack *a, t_stack *b);
int		push_a(t_stack *a, t_stack *b);
int		push_b(t_stack *a, t_stack *b);
int		rotate_a(t_stack *a);
int		rotate_b(t_stack *a, t_stack *b);
int		rotate_both(t_stack *a, t_stack *b);
int		reverse_ra(t_stack *a);
int		reverse_rb(t_stack *a, t_stack *b);
int		reverse_rboth(t_stack *a, t_stack *b);
void	only_three(t_stack *a);
void	only_five(t_stack *a, t_stack *b);
void	only_hundred(t_stack *a, t_stack *b, t_chunk *chunk);
void	only_five_hundred(t_stack *a, t_stack *b, t_chunk *chunk);
void	find_max_min(t_stack *b);
void	sort_stack(t_stack *a, t_stack *b);
int		is_list_sorted(t_stack *a);
int		how_much_chunk(int len);
int		argv_errors(char **argv);
int		stack_a_err(long int *tab, int len);
void	print_stack(t_stack *a);

#endif