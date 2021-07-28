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

void    only_hundred(s_stack *a, s_stack *b)
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

}