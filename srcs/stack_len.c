#include "../libps.h"

void	insertion_sort(s_stack *a)
{
	int	i;
	int	temp;
	int	min_value;

	i = 0;
	min_value = a->tab[i];
	temp = 0;
	while (a->tab[i])
	{
//printf("tab  [%d]  \n", a->tab[i]);
		if (a->tab[i] < min_value)
		{
			min_value = a->tab[i];
			temp = i;
		}
//printf("temp[%d] first[%d] min [%d] \n", a->tab[temp], a->tab[0], min_value);
		i++;
	}
//printf("tab hey\n");
	a->tab[temp] = a->tab[0];
	a->tab[0] = min_value;
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

/*void    only_hundred(s_stack *a, s_stack *b)
{
	int i;
	
printf("   coucou\n ");
//(void)i;
	i = a->len;
	while (i >= 0)
	{
		insertion_sort(a);
		push_b(a, b);
		i--;
	}
	i = 0;
	while (b->tab[i] && i < b->len)
	{
		printf("b tab[%d][%d]  \n", i, b->tab[i]);
		i++;
	}
	i = b->len;
	while (i > 0)
	{
		push_a(a, b);
		i--;
	}
	i = 0;
	while (a->tab[i] && i < a->len)
	{
		printf("a tab[%d][%d]  \n", i, a->tab[i]);
		i++;
	}	

}*/

int	find_chunk(s_stack *a, int chunk_min, int chunk_max)
{
	int	i;
	int	hold_first;
	int	hold_second;

	i = 0;
	hold_first = 0;
	hold_second = 0;
	while (i < a->len)
	{
		if (a->tab[i] >= chunk_min && a->tab[i] <= chunk_max)
		{
			hold_first = i;
			break ;
		}
		i++;
	}
	i = a->len;
	while (i > 0)
	{
		if (a->tab[i] >= chunk_min && a->tab[i] <= chunk_max)
		{
			hold_second = i;
			break ;
		}
		i--;
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

int	is_stack_sort(s_stack *b)
{
	int	i;

	i = 0;
//	printf("b->len %d\n", b->len);
	if (b->len < 2)
		return (1);
	i = -1;
	while (b->tab[++i])
		printf("   %d[%d]  \n", i, b->tab[i]);
	i = 0;
	while (b->tab[i] && i < b->len)
	{
		printf("tab = %d, i + 1 %d\n", b->tab[i], b->tab[i + 1]);
		if (b->tab[i + 1] && b->tab[i] > b->tab[i + 1])
			return (0);
		i++;
	}
	//	printf("  ho[%d]  \n", b->tab[0]);
	i = -1;
	while (b->tab[++i])
		printf("   %d[%d]  \n", i, b->tab[i]);
	return (1);
}

void	only_hundred(s_stack *a, s_stack *b)
{
	int	i;
	while (find_chunk(a, 0, 19))
	{
		while (!is_stack_sort(b))
			rotate_b(b);
		push_b(a, b);
	}
	i = -1;
	while (b->tab[++i])
		printf(" %d[%d]  \n", i, b->tab[i]);
	 while (find_chunk(a, 20, 39))
	{
		while (!is_stack_sort(b))
			rotate_b(b);
		push_b(a, b);
	}
/*	while (find_chunk(a, 40, 59))
	{
		while (!is_stack_sort(b))
			rotate_b(b);
		push_b(a, b);
	}
	while (find_chunk(a, 60, 79))
	{
		while (!is_stack_sort(b))
			rotate_b(b);
		push_b(a, b);
	}
	while (find_chunk(a, 80, 99))
	{
		while (!is_stack_sort(b))
			rotate_b(b);
		push_b(a, b);
	}*/
}