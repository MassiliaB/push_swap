/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_to_five.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula </var/mail/masboula>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 18:04:47 by masboula          #+#    #+#             */
/*   Updated: 2021/08/12 18:04:49 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libps.h"

void	sort_a(t_stack *a)
{
	int	i;

	find_max_min(a);
	if (a->tab[0] != a->tab[a->min])
	{
		i = a->min;
		if (i < a->len / 2)
		{
			while (i > 0)
			{
				rotate_a(a);
				i--;
			}
		}
		else
		{
			while (i < a->len)
			{
				reverse_ra(a);
				i++;
			}
		}
	}
}

void	only_three(t_stack *a)
{
	if (is_list_sorted(a))
		;
	else if (a->len == 2)
	{
		if (a->tab[1] < a->tab[0])
			swap_a(a);
	}
	else
	{
		if (a->tab[1] < a->tab[0] && a->tab[0] < a->tab[2])
			swap_a(a);
		else if (a->tab[1] < a->tab[0] && a->tab[2] < a->tab[1])
		{
			swap_a(a);
			reverse_ra(a);
		}
		else if (a->tab[0] < a->tab[2] && a->tab[2] < a->tab[1])
		{
			swap_a(a);
			rotate_a(a);
		}
		else if (a->tab[1] < a->tab[0])
			rotate_a(a);
		else if (a->tab[1] > a->tab[0])
			reverse_ra(a);
	}
}

void	only_five(t_stack *a, t_stack *b)
{
	int	max;

	max = a->len;
	while (max-- > 3)
	{
		sort_a(a);
		push_b(a, b);
	}
	only_three(a);
	while (b->len)
	{
		push_a(a, b);
		if (a->tab[0] > a->tab[1])
			swap_a(a);
	}
}
