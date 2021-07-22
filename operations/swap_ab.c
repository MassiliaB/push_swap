#include "../libps.h"

int swap_a(char **a)
{
	char *temp;

	if (!a || !a[0] || !a[1])
		return (0);
	temp = a[0];
	a[0] = a[1];
	a[1] = temp;
	write(1, "sa\n", 3);
	return (1);
}

int swap_b(char **b)
{
	char *temp;

	if (!b || !b[0] || !b[1])
		return (0);
	temp = b[0];
	b[0] = b[1];
	b[1] = temp;
	write(1, "sb\n", 3);
	return (1);
}

int	swap_both(char **a, char **b)
{
	swap_b(b);
	swap_a(a);
	write(1, "ss\n", 3);
	return (1);
}