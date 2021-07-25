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
	char	**tab;
	int		len;
}				s_stack;

void	clean_all(char **a_tab);
int		is_double(char **all_s, char *str, int i);
int		number_arg(char **arg);
int		len_num(char *arg);
int		swap_a(s_stack *a);
int		swap_b(s_stack *b);
int		swap_both(s_stack *a, s_stack *b);
int		push_a(s_stack *a, s_stack *b);
int		push_b(s_stack *a, s_stack *b);
int		rotate_a(s_stack *a);
int		rotate_b(s_stack *b);
int		rotate_both(s_stack *a, s_stack *b);
int		reverse_ra(s_stack *a);
int		reverse_rb(s_stack *b);
int		reverse_rboth(s_stack *b, s_stack *a);

#endif