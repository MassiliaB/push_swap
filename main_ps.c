#include "libps.h"

int	argv_errors(char **argv, int argc)
{
	int	i;
	int	j;
	int	num;

	if (argc == 0)
		return (0);
	i = 0;
	while (argv[i])
	{
		if (!is_double(argv, *(argv + i), i))
			return (0);
		j = -1;
		while (argv[i][++j])
			if (argv[i][j] != ' ' && !ft_isdigit(argv[i][j]))
				return (0);
		num = ft_atoi(argv[i]); // REGLER INT_MIN MAX
		if (num > INT_MAX || num < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

char	**stack_a(char **argv, s_stack *a)
{
	int		i;
	int		j;
	int		k;
	int		c;
	char	**tab;

	i = -1;
	k = 0;
	a->tab = malloc(sizeof(char **) * (number_arg(argv) + 1));
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			while (!ft_isdigit(argv[i][j]))
				j++;
			a->tab[k] = malloc(sizeof(char *) * (len_num(argv[i] + j) + 1));
			c = 0;
			if (ft_isdigit(argv[i][j]))
				a->tab[k][c++] = argv[i][j];
			a->tab[k++][c] = '\0';
		}
	}
	a->len = k;
	tab[k] = 0;
	return (tab);
}

int	main(int ac, char **av)
{
	int		i;
	s_stack	a;
	s_stack	b;

	if (!argv_errors(av + 1, ac - 1) || !init_ab(a, b))
		return (write(2, "Error\n", 6));
	a.len = 0;
	a.tab = stack_a(av + 1, &a);

	swap_a(&a);
	push_a(&a, &b);
	i = 0;
	while (a.tab[i])
	{	printf("after tab[%d][%s]\n", i, a.tab[i]);
		i++;}

	clean_all(a);
	return (0);
}