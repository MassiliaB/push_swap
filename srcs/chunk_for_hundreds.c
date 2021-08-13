/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_for_hundreds.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula </var/mail/masboula>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 10:18:52 by masboula          #+#    #+#             */
/*   Updated: 2021/08/13 10:18:57 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libps.h"

void	find_max_min(t_stack *b)
{
	int	i;

	i = 0;
	b->max = 0;
	b->min = 0;
	while (i < b->len)
	{
		if (b->tab[i] > b->tab[b->max])
			b->max = i;
		if (b->tab[i] < b->tab[b->min])
			b->min = i;
		i++;
	}
}

void	sort_stack(t_stack *a, t_stack *b)
{
	int	i;

	find_max_min(b);
	if (b->tab[0] != b->tab[b->max])
	{
		i = b->max;
		if (b->max < b->len / 2)
		{
			while (i > 0)
			{
				rotate_b(a, b);
				i--;
			}
		}
		else
		{
			while (i < b->len)
			{
				reverse_rb(a, b);
				i++;
			}
		}
	}
}

int	min_in_chunk(int to_hold, t_stack *a, t_chunk *chunk)
{
	int	i;

	if (to_hold == 1)
	{
		i = -1;
		while (++i < a->len)
			if (i < a->len && (a->tab[i] <= chunk->max))
				return (i);
	}
	else
	{
		i = a->len + 1;
		while (--i >= 0)
			if (i < a->len && i >= 0 && (a->tab[i] <= chunk->max))
				return (i);
	}
	return (-1);
}

int	sort_in_chunk(t_stack *a, t_chunk *chunk)
{
	int	hold_first;
	int	hold_sec;

	hold_first = min_in_chunk(1, a, chunk);
	hold_sec = min_in_chunk(0, a, chunk);
	if (hold_first <= a->len / 2)
	{
		while (hold_first > 0)
		{
			rotate_a(a);
			hold_first--;
		}
	}
	else
	{
		while (hold_sec > 0)
		{
			reverse_ra(a);
			hold_sec--;
		}
	}
	if (hold_first == -1 && hold_sec == -1)
		return (0);
	return (1);
}
