#include "../libps.h"

int	reverse_ra(s_stack *a)
{
	int		i;
	char	*temp;

	if (!a || !a->tab || a->len < 2)
		return (0);
	i = a->len - 1;
	temp = a->tab[i];
	while (a->tab[i] && i > 0)
	{
		a->tab[i] = a->tab[i - 1];
		i--;
	}
	a->tab[i] = temp;
	a->tab[a->len] = 0;
	write(1, "rra\n", 4);
	return (1);
}

int	reverse_rb(s_stack *b)
{
	int		i;
	char	*temp;

	if (!b || !b->tab || b->len < 2)
		return (0);
	i = b->len;
	temp = b->tab[i];
	while (b->tab[i] && i > 0)
	{
		b->tab[i] = b->tab[i - 1];
		i--;
	}
	b->tab[i] = temp;
	b->tab[b->len] = 0;
	write(1, "rrb\n", 4);
	return (1);
}

int	reverse_rboth(s_stack *b, s_stack *a)
{
	reverse_ra(a);
	reverse_rb(b);
	write(1, "rrr\n", 4);
	return (0);
}