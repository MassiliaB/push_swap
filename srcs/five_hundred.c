#include "../libps.h"

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
