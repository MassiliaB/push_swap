#include "../libps.h"

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

