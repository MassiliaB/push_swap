#include "../libps.h"

void	sort_stack(s_stack *a, s_stack *b)
{
	int	i;

	find_max_min(b);
	if (b->tab[0] != b->tab[b->max])
	{
		i = b->max;
		if (b->max < b->len / 2)
			while (i > 0)
			{
				rotate_b(a, b);
				i--;
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
}

int	min_in_chunk(int to_hold, s_stack *a, s_chunk *chunk)
{
	int i;

	//	printf("len = %d, chunk min %d, chunk max %ld\n", a->len, chunk->min, chunk->max);
	if (to_hold == 1)
	{
		i = -1;
		while (++i < a->len)
		{
	//	printf("tab %ld\n", a->tab[i]);
			if (i < a->len && (a->tab[i] >= chunk->min && a->tab[i] <= chunk->max))
		{//printf("tab %ld\n", a->tab[i]);
				return (i);}}
	}
	else
	{
		i = a->len + 1;
		while (--i >= 0)
			if (i < a->len && i >= 0 && (a->tab[i] >= chunk->min && a->tab[i] <= chunk->max))
		{//printf("tab %ld\n", a->tab[i]);
				return (i);}
	}
	return (-1);
}

int	sort_in_chunk(s_stack *a, s_chunk *chunk)
{
	int	hold_first;
	int	hold_sec;

	hold_first = min_in_chunk(1, a, chunk);
	hold_sec = min_in_chunk(0, a, chunk);
	if (hold_first <= a->len / 2)
		while (hold_first > 0)
		{
			rotate_a(a);
			hold_first--;
		}
	else
		while (hold_sec > 0)
		{
			reverse_ra(a);
			hold_sec--;
		}
	if (hold_first == -1 && hold_sec == -1)
		return (0);
	return (1);
}

int	how_much_chunk(int len)
{
	if (len <= 50)
		return (3);
	if (len <= 100)
		return (5);
	if (len <= 300)
		return (7);
	return (12);
}

void	only_hundred(s_stack *a, s_stack *b, s_chunk *chunk)
{
	int	nb_max;

	find_max_min(a);
	chunk->cut = a->tab[a->max] / how_much_chunk(a->len);
	chunk->min = a->tab[a->min];
	chunk->max = chunk->cut;
	nb_max = a->tab[a->max];
	while (a->len && chunk->min <= nb_max)
	{
		if (!sort_in_chunk(a, chunk))
		{
			chunk->min += chunk->cut;
			chunk->max += chunk->cut;
		}
		else
		{
			sort_stack(a, b);
			push_b(a, b);
		}
	}
	while (b->len)
	{
		sort_stack(a, b);
		push_a(a, b);
	}
}

void	only_five_hundred(s_stack *a, s_stack *b, s_chunk *chunk)
{
	int	nb_max;

	find_max_min(a);
	chunk->cut = a->tab[a->max] / how_much_chunk(a->len);
	chunk->min = a->tab[a->min];
	if (chunk->min / chunk->cut < 0)
		chunk->max = a->tab[a->min] / 2;
	else
		chunk->max = chunk->cut;
	nb_max = a->tab[a->max];
	while (a->len && chunk->min < nb_max)
	{
		if (!sort_in_chunk(a, chunk))
		{
			chunk->min += chunk->cut;
			chunk->max += chunk->cut;
		}
		else
		{
			push_b(a, b);
			sort_stack(a, b);
		}
	}
	while (b->len)
	{
		sort_stack(a, b);
		push_a(a, b);
	}
}
