/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula </var/mail/masboula>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 18:04:57 by masboula          #+#    #+#             */
/*   Updated: 2021/08/12 18:06:25 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libps.h"

int	is_double(long int *tab, int num, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (tab[j] == num)
			return (1);
		j++;
	}
	return (0);
}

int	number_arg(char **arg)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (arg[i])
	{
		j = 0;
		while (arg[i][j] && j < ft_strlen(arg[i]))
		{
			while (ft_isdigit(arg[i][j]))
				j++;
			if (ft_isdigit(arg[i][j - 1]))
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	len_num(char *arg)
{
	int	i;

	i = 0;
	while (ft_isdigit(arg[i]) || arg[i] == '+'
		|| arg[i] == '-')
	{
		i++;
		if (arg[i] == ' ')
			return (i + 1);
	}
	return (i);
}
