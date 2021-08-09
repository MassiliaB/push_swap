#include "../libps.h"

void	only_five_hundred(s_stack *a, s_stack *b)
{
	int	max;
	int	min;

	min = 0;
	max = 45;
	while (sort_in_chunk(a, b, min, max) || max <= 500)
	{
		push_b(a, b);
		if (!sort_in_chunk(a, b, min, max))
		{
			min += 46;
			max += 46;
		}
	}
	while (a->len)
	{
		sort_in_chunk(a, b, 0, 500);
		push_b(a, b);
	}	
	while (b->len)
	{
		sort_stack(a, b);
		push_a(a, b);
	}
}