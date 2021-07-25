#include "../libps.h"

int	push_a(s_stack *a, s_stack *b)
{
	int		i;

	if (!b || !a || !a->tab || !b->tab
		|| !a->len )
		return (0);
	i = a->len - 1;
	a->tab[i + 2] = 0;
	while (a->tab[i])
	{
		a->tab[i + 1] = a->tab[i];
		printf("a[%d][%s]\n", i+ 1, a->tab[i + 1]);
		i--;
	}
	a->tab[0] = a->tab[0];
	printf("a[%s]\n", a->tab[0]);
	write(1, "pa\n", 3);
	return (1);
}

int	push_b(s_stack *a, s_stack *b)
{
	int		i;

	if (!b || !a || !a->tab || !b->tab
		|| !a->len )
		return (0);
	i = b->len + 1;
	b->tab[i + 1] = 0;
	while (b->tab[i])
	{
		b->tab[i + 1] = b->tab[i];
		i--;
	}
	b->tab[0] = a->tab[0];
	write(1, "pb\n", 3);
	return (1);
}