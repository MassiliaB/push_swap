/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula </var/mail/masboula>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 18:04:16 by masboula          #+#    #+#             */
/*   Updated: 2021/08/12 18:07:27 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libps.h"

int	is_list_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->len)
	{
		if (i + 1 < a->len && a->tab[i] > a->tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	argv_errors(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != '-'
				&& argv[i][j] != '+' && argv[i][j] != ' ')
				return (0);
			if ((argv[i][j] == '-' || argv[i][j] == '+')
				&& !ft_isdigit(argv[i][j + 1]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	stack_a_err(long int *tab, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		if (is_double(tab, tab[i], i))
			return (0);
		if (tab[i] < INT_MIN || tab[i] > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}
