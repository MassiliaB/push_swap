#include "../libps.h"

void	only_three(s_stack *a, s_stack *b)
{
	if (a->len == 2)
	{
		if ((a->tab[0] && a->tab[1]) && a->tab[1] < a->tab[0])
			swap_a(a, b);
	}
	else
	{
		if ((a->tab[0] && a->tab[1] && a->tab[2])
			&& a->tab[2] < a->tab[0] && a->tab[1] < a->tab[2])
			rotate_a(a, b);
		if ((a->tab[0] && a->tab[1]) && a->tab[1] < a->tab[0])
			swap_a(a, b);
		if ((a->tab[0] && a->tab[1] && a->tab[2])
			&& a->tab[0] < a->tab[1] && a->tab[2] < a->tab[0])
			reverse_ra(a, b);
		if ((a->tab[0] && a->tab[1] && a->tab[2])
			&& a->tab[2] < a->tab[1] && a->tab[0] < a->tab[2])
			swap_a(a, b);
		if ((a->tab[0] && a->tab[2]) && a->tab[2] < a->tab[0])
			rotate_a(a, b);
	}
}

void	only_five(s_stack *a, s_stack *b)
{
	int	i;
	int	max;

	max = a->len;
	i = 0;
	while (max-- > 3)
		push_b(a, b);
	only_three(a, b);
	push_a(a, b);
	if ((a->tab[0] && a->tab[1]) && a->tab[1] < a->tab[0])
	{
		rotate_a(a, b);
		if ((a->tab[a->len - 1] && a->tab[a->len - 2])
			&& a->tab[a->len - 1] < a->tab[a->len - 2])
		{
			only_five(a, b);
			return ;
		}
	}
	push_a(a, b);
	if ((a->tab[0] && a->tab[1]) && a->tab[1] < a->tab[0])
		swap_a(a, b);
}
