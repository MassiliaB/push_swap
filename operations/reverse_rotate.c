#include "../libps.h"

int	reverse_ra(s_stack *a, s_stack *b)
{
	int		i;
	int		temp;

	if (!a || !a->tab || a->len < 2)
		return (0);
	i = a->len - 1;
	temp = a->tab[i];
	while (i > 0)
	{
		a->tab[i] = a->tab[i - 1];
		i--;
	}
	a->tab[i] = temp;
	a->tab[a->len] = 0;
	write(1, "rra\n", 4);
	print_stack(a, b);
	return (1);
}

int	reverse_rb(s_stack *a, s_stack *b)
{
	int		i;
	int		temp;

	if (!b || !b->tab || b->len < 2)
		return (0);
	i = b->len - 1;
	temp = b->tab[i];
	while (i > 0)
	{
		b->tab[i] = b->tab[i - 1];
		i--;
	}
	b->tab[i] = temp;
	b->tab[b->len] = 0;
	write(1, "rrb\n", 4);
	print_stack(a, b);
	return (1);
}

int	reverse_rboth(s_stack *a, s_stack *b)
{
	reverse_ra(a, b);
	reverse_rb(a, b);
	write(1, "rrr\n", 4);
	print_stack(a, b);
	return (0);
}