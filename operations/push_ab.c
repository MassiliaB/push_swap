#include "../libps.h"

void	remove_from_tab(s_stack *temp)
{
	int	i;

	i = -1;
	while (++i < temp->len)
		temp->tab[i] = temp->tab[i + 1];
	temp->tab[temp->len] = 0;
	temp->len--;
}

int	push_a(s_stack *a, s_stack *b)
{
	int		i;

	if (!a || !a->tab || !b || !b->tab || !b->len)
		return (0);
	i = a->len - 1;
	while (i >= 0)
	{
		a->tab[i + 1] = a->tab[i];
		i--;
	}
	a->tab[0] = b->tab[0];
	a->len++;
	remove_from_tab(b);
	write(1, "pa\n", 3);
	print_stack(a, b);
	a->nbr_mooves += 1;
	return (1);
}

int	push_b(s_stack *a, s_stack *b)
{
	int		i;

	if (!b || !a || !a->tab || !b->tab || !a->len)
		return (0);
	i = b->len;
	if (b->len != 0)
	{
		while (i >= 0)
		{
			b->tab[i + 1] = b->tab[i];
			i--;
		}
	}
	b->tab[0] = a->tab[0];
	b->len++;
	remove_from_tab(a);
	write(1, "pb\n", 3);
	print_stack(a, b);
	a->nbr_mooves += 1;
	return (1);
}