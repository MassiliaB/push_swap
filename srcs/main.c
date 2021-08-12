/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula </var/mail/masboula>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 18:04:35 by masboula          #+#    #+#             */
/*   Updated: 2021/08/12 18:15:25 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libps.h"

long int	*stack_a(char **argv, t_stack *a)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	k = 0;
	a->tab = malloc(sizeof(int *) * (number_arg(argv)) + 1);
	if (!a->tab)
		return (0);
	while (argv[++i] && i < number_arg(argv))
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) || argv[i][j] == '+'
				|| argv[i][j] == '-')
			{
				a->tab[k++] = ft_atoi(&argv[i][j]);
				j += len_num(argv[i] + j);
			}
			else
				j++;
		}
	}
	a->len = k;
	a->tab[k] = '\0';
	return (a->tab);
}

int	id_check(char **argv, t_stack *a, t_stack *b, t_chunk *chunk)
{
	if (!argv_errors(argv + 1))
		return (0);
	a->len = 0;
	b->len = 0;
	b->max = 0;
	b->min = 0;
	a->max = 0;
	a->min = 0;
	chunk->min = 0;
	chunk->max = 0;
	a->nbr_mooves = 0;
	a->tab = stack_a(argv + 1, a);
	b->tab = malloc(sizeof(int *) * (number_arg(argv)));
	if (!b->tab)
		return (0);
	if (!stack_a_err(a->tab, a->len))
	{
		clean_all(a, b);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	int		i;
	t_stack	a;
	t_stack	b;
	t_chunk	chunk;

	if (ac == 1)
		return (0);
	if (!id_check(av, &a, &b, &chunk))
		return (write(2, "Error\n", 6));
	i = -1;
	while (++i < number_arg(av))
		b.tab[i] = 0;
	a.b = &b;
	if (is_list_sorted(&a))
		;
	else if (a.len == 2 || a.len == 3)
		only_three(&a);
	else if (a.len >= 4 && a.len <= 5)
		only_five(&a, &b);
	else if (a.len >= 6 && a.len <= 100)
		only_hundred(&a, &b, &chunk);
	else if (a.len >= 101 && a.len <= 500)
		only_five_hundred(&a, &b, &chunk);
	clean_all(&a, &b);
	return (0);
}
//printf("numbers of mooves = %d \n", a.nbr_mooves);
