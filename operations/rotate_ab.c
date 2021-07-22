#include "../libps.h"

int	rotate_a(char **a)
{
	int		i;
	char	*temp;

	if (!a || !a[0] || !a[1])
		return (0);
	temp = a[0];
	i = 0;
	while (a[i])
	{
		a[i] = a[i + 1];
		i++;
	}
	a[i] = temp;
	a[i + 1] = 0;
	write(1, "ra\n", 3);
	return (1);
}

int	rotate_b(char **b)
{
	int		i;
	char	*temp;

	if (!b || !b[0] || !b[1])
		return (0);
	temp = b[0];
	i = 0;
	while (b[i])
	{
		b[i] = b[i + 1];
		i++;
	}
	b[i] = temp;
	b[i + 1] = 0;
	write(1, "rb\n", 3);
	return (1);
}

int	rotate_both(char **a, char **b)
{
	rotate_a(a);
	rotate_b(b);
	write(1, "rr\n", 3);
	return (0);
}