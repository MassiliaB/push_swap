#include "../libps.h"

int	reverse_ra(char **a, s_tab *stack)
{
	int		i;
	char	*temp;

	if (!a || !a[0] || !a[1])
		return (0);
	i = stack->len_a;
	temp = a[i];
	while (a[i])
	{
		a[i] = a[i - 1];
		i--;
	}
	a[i] = temp;
	a[stack->len_a + 1] = 0;
	write(1, "ra\n", 3);
	return (1);
}

int	reverse_rb(char **b, s_tab *stack)
{
	int		i;
	char	*temp;

	if (!b || !b[0] || !b[1])
		return (0);
	i = stack->len_b;
	temp = b[i];
	while (b[i])
	{
		b[i] = b[i - 1];
		i--;
	}
	b[i] = temp;
	b[stack->len_b + 1] = 0;
	write(1, "ra\n", 3);
	return (1);
}

int	reverse_rboth(char **a, char **b, s_tab *stack)
{
	reverse_ra(a, stack);
	reverse_rb(b, stack);
	write(1, "rr\n", 3);
	return (0);
}