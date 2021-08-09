#include "../libps.h"

void	sort_a(s_stack *a, s_stack *b)
{
	int	i;

	find_max_min(a);
	if (a->tab[0] != a->tab[a->min])
	{
		i = a->min;
		if (i <= a->len / 2)
		{
			while (i > 0)
			{
				rotate_a(a, b);
				i--;
			}
		}
		else
		{
			while (i < a->len)
			{
				reverse_ra(a, b);
				i++;
			}
		}
	}
}

void	only_three(s_stack *a, s_stack *b)
{
	if (is_list_sorted(a))
		;
	else if (a->len == 2)
	{
		if (a->tab[1] < a->tab[0])
			swap_a(a, b);
	}
	else
	{
		if (a->tab[1] < a->tab[0] && a->tab[0] < a->tab[2])
			swap_a(a, b);
		else if (a->tab[1] < a->tab[0] && a->tab[2] < a->tab[1])
		{
			swap_a(a, b);
			reverse_ra(a, b);
		}
		else if (a->tab[0] < a->tab[2] && a->tab[2] < a->tab[1])
		{
			swap_a(a, b);
			rotate_a(a, b);
		}
		else if (a->tab[1] < a->tab[0])
			rotate_a(a, b);
		else if (a->tab[1] > a->tab[0])
			reverse_ra(a, b);
	}
}

void	only_five(s_stack *a, s_stack *b)
{
	int	max;

	max = a->len;
	while (max-- > 3)
	{
		sort_a(a, b);
		push_b(a, b);
	}
	only_three(a, b);
	while (b->len)
	{
		push_a(a, b);
		if (a->tab[0] > a->tab[1])
			swap_a(a, b);
	}
}
