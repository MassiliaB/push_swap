#include "../libps.h"

int	rotate_a(s_stack *a)
{
	int		i;
	char	*temp;

	if (!a || !a->tab || !a->len)
		return (0);
	temp = a->tab[0];
	i = 0;
	while (a->tab[i])
	{
		a->tab[i] = a->tab[i + 1];
		i++;
	}
	a->tab[i] = temp;
	a->tab[i + 1] = 0;
	write(1, "ra\n", 3);
	return (1);
}

int	rotate_b(s_stack *b)
{
	int		i;
	char	*temp;

	if (!b || !b->tab || !b->len)
		return (0);
	temp = b->tab[0];
	i = 0;
	while (b->tab[i])
	{
		b->tab[i] = b->tab[i + 1];
		i++;
	}
	b->tab[i] = temp;
	b->tab[i + 1] = 0;
	write(1, "rb\n", 3);
	return (1);
}

int	rotate_both(s_stack *a, s_stack *b)
{
	rotate_a(a);
	rotate_b(b);
	write(1, "rr\n", 3);
	return (0);
}