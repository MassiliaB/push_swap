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

char	**stack_a(char **argv, s_tab *stack)
{
	int		i;
	int		j;
	int		k;
	int		c;
	char	**tab;

	i = -1;
	k = 0;
	tab = malloc(sizeof(char **) * (number_arg(argv) + 1));
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			while (!ft_isdigit(argv[i][j]))
				j++;
			tab[k] = malloc(sizeof(char *) * (len_num(argv[i] + j) + 1));
			c = 0;
			if (ft_isdigit(argv[i][j]))
				tab[k][c++] = argv[i][j];
			tab[k++][c] = '\0';
		}
	}
	stack->len_a = k;
	tab[k] = 0;
	return (tab);
}

int	main(int ac, char **av)
{
	char	**a_tab;
	int		i;
	s_tab	stack;

	if (!argv_errors(av + 1, ac - 1))
		return (write(2, "Error\n", 6));
	stack.len_a = 0;
	a_tab = stack_a(av + 1, &stack);

	i = 0;
	while (a_tab[i])
	{	printf("before tab[%d][%s]\n", i, a_tab[i]);
		i++;}

	swap_a(a_tab);
	i = 0;
	while (a_tab[i])
	{	printf("after swap tab[%d][%s]\n", i, a_tab[i]);
		i++;}

	char **tab_2;
	tab_2 = malloc(sizeof(char *) * (2 + 1));
	tab_2[0] = "20";
	tab_2[1] = "21";
	tab_2[2] = 0;

	push_a(a_tab, tab_2, &stack);
	i = 0;
	while (a_tab[i])
	{	printf("after tab[%d][%s]\n", i, a_tab[i]);
		i++;}

	clean_all(a_tab);
	return (0);
}