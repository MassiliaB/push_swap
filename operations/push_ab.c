#include "../libps.h"

void	remove_from_tab(s_stack *temp)
{
	int	i;

	i = -1;
	while (temp->tab[++i] && i < temp->len - 1)
		temp->tab[i] = temp->tab[i + 1];
	temp->tab[temp->len] = 0;
	temp->len--;
}

int	push_a(s_stack *a, s_stack *b)
{
	int		i;

	if (!a || !a->tab || !b || !b->tab)
		return (0);
	i = a->len - 1;
//	printf("A = i %d\n", i);
	while (i >= 0)
	{
		a->tab[i + 1] = a->tab[i];
	//	printf("A = i %d, tab i [%d]\n", i, b->tab[i]);
		i--;
	}
	a->tab[0] = b->tab[0];
//	printf("len = %d\n", a->len);
//	a->tab[a->len + 1] = 0;
	a->len++;
	remove_from_tab(b);
	write(1, "pa\n", 3);
	return (1);
}

int	push_b(s_stack *a, s_stack *b)
{
	int		i;

	if (!b || !a || !a->tab || !b->tab)
		return (0);
	i = b->len;
//	printf("i %d\n", i);
	while (i >= 1)
	{
		b->tab[i] = b->tab[i - 1];
//		printf("B = i %d, tab i [%d]\n", i, b->tab[i]);
		i--;
	}
	b->tab[0] = a->tab[0];
//	printf("tab [%s], %d\n", b->tab[0], b->len);
//	b->tab[b->len + 1] = 0;
	b->len++;
	remove_from_tab(a);
	write(1, "pb\n", 3);
/*	i = 0;
	while (a->tab[i])
		printf("  [%s]  \n", a->tab[i++]);*/
	return (1);
}