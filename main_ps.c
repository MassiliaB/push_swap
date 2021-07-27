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

	i = -1;
	k = 0;
	a->tab = malloc(sizeof(char **) * (number_arg(argv) + 1));
	if (!a->tab)
		return (0);
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j] && j < ft_strlen(argv[i]))
		{
			while (!ft_isdigit(argv[i][j]))
				j++;
			a->tab[k] = malloc(sizeof(char *) * (len_num(argv[i] + j) + 1));
			if (!a->tab[k])
				return (0);
			c = 0;
			while (ft_isdigit(argv[i][j]))
				a->tab[k][c++] = argv[i][j++];
			a->tab[k++][c] = '\0';
		}
	} 
	a->len = k;
	a->tab[k] = 0;
	return (a->tab);
}

int	main(int ac, char **av)
{
	int		i;
	s_stack	a;
	s_stack	b;

	if (!argv_errors(av + 1, ac - 1))
		return (write(2, "Error\n", 6));
	a.len = 0;
	b.len = 0;
	a.tab = stack_a(av + 1, &a);
	b.tab = malloc(sizeof(char **) * (number_arg(av + 1) + 1));
	if (!b.tab)
		return (0);

/*--------------------------------------------------------*/
	i = -1;
	while (a.tab[++i])
		printf("   [%s]  \n", a.tab[i]);
	printf("-----------\n");
	printf("    a.     \n");
/*--------------------------------------------------------*/

	if (a.len <= 3)
		only_three(&a);
	if (a.len <= 5)
		only_five(&a, &b);

/*--------------------------------------------------------*/
	i = -1;
	while (a.tab[++i])
	{
		printf("   [%s]  ", a.tab[i]);
		if (b.tab[i])
			printf("      [%s]  ", b.tab[i]);
		printf("\n");
	}
	printf("---------- "); printf(" ----------\n");
	printf("    a.     "); printf("    b.     \n");
/*--------------------------------------------------------*/

	clean_all(&a);
	return (0);
}