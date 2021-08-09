#include "../libps.h"

void	sort_stack(s_stack *a, s_stack *b)
{
	int	i;

	find_max_min(b);
	if (b->tab[0] != b->tab[b->min])
	{
		i = b->max;
		if (b->max <= b->len / 2)
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
}

int	sort_in_chunk(s_stack *a, s_stack *b, int chunk_min, int chunk_max)
{
	int	i;
	int	hold_first;
	int	hold_second;

	i = -1;
	hold_first = 0;
	hold_second = 0;
	while (++i < a->len)
	{
		if (a->tab[i] && (a->tab[i] >= chunk_min && a->tab[i] <= chunk_max))
		{
			hold_first = i;
			break ;
		}
	}
	i = a->len + 1;
	while (--i > 0)
	{
	//	printf("TAB [%d] LEN [%d]  \n", a->tab[i], i);
		if (a->tab[i] && (a->tab[i] >= chunk_min && a->tab[i] <= chunk_max))
		{
			hold_second = i;
			break ;
		}
	}
//	printf("FIRST [%d][%d] SEC [%d][%d] LEN/2 %d  \n", hold_first, a->tab[hold_first], hold_second, a->tab[hold_second], a->len /2);
	if (hold_first <= a->len / 2)
		while (hold_first > 0)
		{
			rotate_a(a, b);
			hold_first--;
		}
	else
		while (hold_second > 0)
		{
			reverse_ra(a, b);
			hold_second--;
		}
	if (!hold_first && !hold_second)
		return (0);
	//printf("FIRST [%d] SEC [%d] LEN/2 %d  \n", hold_first, hold_second, a->len /2);
	return (1);
}


void	only_hundred(s_stack *a, s_stack *b)
{
	int	max;
	int	min;

	min = INT_MIN;
	max = 19;
	while (sort_in_chunk(a, b, min, max) || max <= 100)
	{
		push_b(a, b);
		if (!sort_in_chunk(a, b, min, max))
		{
			min += 20;
			max += 20;
		}
	}
	while (a->len)
	{
		sort_in_chunk(a, b, 0, 100);
		push_b(a, b);
	}	
	while (b->len)
	{
		sort_stack(a, b);
		push_a(a, b);
	}
}

