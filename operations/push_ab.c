#include "../libps.h"

int	push_a(s_stack *a, s_stack *b)
{
	int		i;

	if (!a || !a->tab || !b || !b->tab)
		return (0);
	i = a->len - 1;
	a->tab[i + 2] = 0;
	while (a->tab[i])
	{
		a->tab[i + 1] = a->tab[i];
		i--;
	}
	a->tab[0] = a->tab[0];
	write(1, "pa\n", 3);
	return (1);
}

int	push_b(s_stack *a, s_stack *b)
{
	int		i;

	if (!b || !a || !a->tab)
		return (0);
	i = b->len;
	while (b->tab[i] && i > 1)
	{
		b->tab[i] = b->tab[i - 1];
		i--;
	}
	b->tab[0] = ft_strdup(a->tab[0]);
	b->tab[b->len + 1] = 0;
	b->len++;
	remove_from_tab(a);
	write(1, "pb\n", 3);
	return (1);
}