#include "../libps.h"

void	remove_from_tab(s_stack *temp)
{
/*	int	i;
	char *tmp;

	i = temp->len - 1;
	tmp = temp->tab[i];
	while (temp->tab[i] && i > 0)
	{
		temp->tab[i] = temp->tab[i - 1];
		i--;
	}
	temp->tab[i] = tmp;
	temp->tab[temp->len - 1] = 0;*/
	rotate_a(temp);
	temp->tab[temp->len - 1] = 0;
}

void    only_three(s_stack *a)
{
	if (a->len == 2)
	{
		if (ft_strcmp(a->tab[1], a->tab[0]) < 0)
			swap_a(a);
	}
	else
	{
		if (ft_strcmp(a->tab[2], a->tab[0]) < 0 && ft_strcmp(a->tab[1], a->tab[2]) < 0)
			rotate_a(a);
		if (ft_strcmp(a->tab[1], a->tab[0]) < 0)
			swap_a(a);
		if (ft_strcmp(a->tab[0], a->tab[1]) < 0 && ft_strcmp(a->tab[2], a->tab[0]) < 0)
			reverse_ra(a);
		if (ft_strcmp(a->tab[2], a->tab[1]) < 0 && ft_strcmp(a->tab[0], a->tab[2]) < 0)
			swap_a(a);
		if (ft_strcmp(a->tab[2], a->tab[0]) < 0)
			rotate_a(a);
	}
}

void    only_five(s_stack *a, s_stack *b)
{
	int	i;
	int	max;

	max = a->len;
	i = 0;
	while (max-- != 3)
		push_b(a, b);
	
}