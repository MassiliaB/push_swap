#include "../libps.h"

void	insertion_sort(s_stack *a)
{
	int	i;
	int j;
	int	temp;

	i = 0;
	j = 0;
	while (a->tab[i])
	{
		j = i + 1;
		while (a->tab[j])
		{
			if (a->tab[j] < a->tab[i])
			{
				temp = a->tab[i];
				a->tab[i] = a->tab[j];
				a->tab[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	only_three(s_stack *a)
{
	if (a->len == 2)
	{
		if (a->tab[1] < a->tab[0])
			swap_a(a);
	}
	else
	{
		if (a->tab[2] < a->tab[0] && a->tab[1] < a->tab[2])
			rotate_a(a);
		if (a->tab[1] < a->tab[0])
			swap_a(a);
		if (a->tab[0] < a->tab[1] && a->tab[2] < a->tab[0])
			reverse_ra(a);
		if (a->tab[2] < a->tab[1] && a->tab[0] < a->tab[2])
			swap_a(a);
		if (a->tab[2] < a->tab[0])
			rotate_a(a);
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
	only_three(a);
	push_a(a, b);
	if (a->tab[1] < a->tab[0])
	{
		rotate_a(a);
		if (a->tab[a->len - 1] < a->tab[a->len - 2])
		{
			only_five(a, b);
			return ;
		}
	}
	push_a(a, b);
	if (a->tab[1] < a->tab[0])
		swap_a(a);
}


int	find_chunk(s_stack *a, int chunk_min, int chunk_max)
{
	int	i;
	int	hold_first;
	int	hold_second;

	i = -1;
	hold_first = 0;
	hold_second = 0;
	while (++i < a->len)
		if (a->tab[i] >= chunk_min && a->tab[i] <= chunk_max)
		{
			hold_first = i;
			break ;
		}
	i = a->len + 1;
	while (--i > 0)
		if (a->tab[i] >= chunk_min && a->tab[i] <= chunk_max)
		{
			hold_second = i;
			break ;
		}
	if (hold_first < a->len / 2)
		while (hold_first > 0)
		{
			rotate_a(a);
			hold_first--;
		}
	else if (hold_second < a->len / 2)
		while (hold_second > 0)
		{
			reverse_ra(a);
			hold_second--;
		}
	if (!hold_first && !hold_second)
		return (0);
	return (1);
}

void	only_hundred(s_stack *a, s_stack *b)
{
	int	min;
	int max;

	min = 0;
	max = 19;
	while (find_chunk(a, 0, max) || max != 99)
	{
		push_b(a, b);
		print_stack(a, b);
		if (!find_chunk(a, min, max))
			max += 20;
	}
	while (b->len)
	{
		push_a(a,b);
		print_stack(a, b);
	}
	insertion_sort(a);
	print_stack(a, b);
}