#include "../libps.h"

int	push_a(char **a, char **b, s_tab *stack)
{
	int		i;

	if (!b || !b[0])
		return (0);
	i = stack->len_a - 1;
	a[i + 2] = 0;
	while (a[i])
	{
		a[i + 1] = a[i];
		printf("a[%d][%s]\n", i+ 1, a[i + 1]);
		i--;
	}
	a[0] = b[0];
	printf("a[%s]\n", a[0]);
	write(1, "pa\n", 3);
	return (1);
}

int	push_b(char **a, char **b, s_tab *stack)
{
	int		i;

	if (!a || !a[0])
		return (0);
	i = stack->len_b + 1;
	b[i + 1] = 0;
	while (b[i])
	{
		b[i + 1] = b[i];
		i--;
	}
	b[0] = a[0];
	write(1, "pb\n", 3);
	return (1);
}