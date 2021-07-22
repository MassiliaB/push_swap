#ifndef _LIBPS_H
# define _LIBPS_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct t_tab
{
	int	len_a;
	int	len_b;
}				s_tab;

void	clean_all(char **a_tab);
int		is_double(char **all_s, char *str, int i);
int		number_arg(char **arg);
int		len_num(char *arg);
int		swap_a(char **a);
int		swap_a(char **a);
int		swap_b(char **b);
int		swap_both(char **a, char **b);
int		push_a(char **a, char **b, s_tab *stack);
int		push_b(char **a, char **b, s_tab *stack);
int		rotate_a(char **a);
int		rotate_b(char **b);
int		rotate_both(char **a, char **b);
int		reverse_ra(char **a, s_tab *stack);
int		reverse_rb(char **b, s_tab *stack);
int		reverse_rboth(char **a, char **b, s_tab *stack);

#endif