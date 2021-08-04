#include "../libps.h"

void	find_max(s_stack *b)
{
	int	i;

	i = 0;
	b->max = b->tab[i];
	while (i < b->len)
	{
		if (b->tab[i] > b->max)
		{
			b->max = b->tab[i];
			b->j = i;
		}
		i++;
	}
}

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


int	find_chunk(s_stack *a, s_stack *b, int chunk_min, int chunk_max)
{
	int	i;
	int	hold_first;
	int	hold_second;

	i = -1;
	hold_first = 0;
	hold_second = 0;
	while (++i < a->len)
		if (a->tab[i] && a->tab[i] >= chunk_min && a->tab[i] <= chunk_max)
		{
			hold_first = i;
			break ;
		}
	i = a->len + 1;
	while (--i > 0)
		if (a->tab[i] && a->tab[i] >= chunk_min && a->tab[i] <= chunk_max)
		{
			hold_second = i;
			break ;
		}
	if (hold_first <= a->len / 2)
		while (hold_first > 0)
		{
			rotate_a(a, b);
			hold_first--;
		}
	else
		while (hold_second >= 0)
		{
			reverse_ra(a, b);
			hold_second--;
		}
	if (!hold_first && !hold_second)
		return (0);
	return (1);
}

void	is_stack_sort(s_stack *a, s_stack *b)
{
	int	i;

	find_min(b);
	i = 0;
	if (b->tab[0] != b->max)
	{
		i = b->j;
		if (b->j <= b->len / 2)
		{
			while (i > 0)
			{
				rotate_b(a, b);
				i--;
			}
		}
		else
		{
			while (i < b->len)
			{
				reverse_rb(a, b);
				i++;
			}
		}
	}
	push_a(a, b);
}

void	only_hundred(s_stack *a, s_stack *b)
{
	int max;
	int min;

	min = 0;
	max = 19;
	while (find_chunk(a, b, min, max) || max <= 99)
	{
		push_b(a, b);
		if (!find_chunk(a, b, min, max))
		{
			min += 20;
			max += 20;
		}
	}
	while (b->len)
		is_stack_sort(a, b);
}

void	only_five_hundred(s_stack *a, s_stack *b)
{
	int max;
	int	min;

	min = 0;
	max = 45;
	while (find_chunk(a, b, min, max) || max <= 499)
	{
		push_b(a, b);
		if (!find_chunk(a, b, min, max))
		{
			min += 46;
			max += 46;
		}
	}
	while (b->len)
		is_stack_sort(a, b);
}