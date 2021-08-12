#include "../libps.h"

int	rotate_a(t_stack *a)
{
	int		i;
	int		temp;

	if (!a || !a->tab || a->len < 2)
		return (0);
	temp = a->tab[0];
	i = 0;
	while (i < a->len - 1)
	{
		a->tab[i] = a->tab[i + 1];
		i++;
	}
	a->tab[i] = temp;
	a->tab[a->len] = 0;
	write(1, "ra\n", 3);
	a->nbr_mooves += 1;
	print_stack(a);
	return (1);
}

int	rotate_b(t_stack *a, t_stack *b)
{
	int		i;
	int		temp;

	if (!b || !b->tab || b->len < 2)
		return (0);
	temp = b->tab[0];
	i = 0;
	while (i < b->len - 1)
	{
		b->tab[i] = b->tab[i + 1];
		i++;
	}
	b->tab[i] = temp;
	b->tab[b->len] = 0;
	write(1, "rb\n", 3);
	a->nbr_mooves += 1;
	print_stack(a);
	return (1);
}

int	rotate_both(t_stack *a, t_stack *b)
{
	rotate_a(a);
	rotate_b(a, b);
	write(1, "rr\n", 3);
	a->nbr_mooves += 1;
	print_stack(a);
	return (0);
}