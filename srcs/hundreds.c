/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula </var/mail/masboula>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 18:04:24 by masboula          #+#    #+#             */
/*   Updated: 2021/08/12 18:12:50 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libps.h"

int	how_much_chunk(int len)
{
	if (len <= 50)
		return (3);
	if (len <= 100)
		return (5);
	if (len <= 300)
		return (7);
	return (12);
}

int	chunk_value(t_stack *a, t_chunk *chunk, int n)
{
	chunk->cut = a->tab[a->max] / how_much_chunk(a->len);
	chunk->min = a->tab[a->min];
	chunk->max = chunk->cut;
	if (n == 1)
		if (chunk->min / chunk->cut < 0)
			chunk->max = a->tab[a->min] / 2;
	return (a->tab[a->max]);
}

void	only_hundred(t_stack *a, t_stack *b, t_chunk *chunk)
{
	int	nb_max;

	find_max_min(a);
	nb_max = chunk_value(a, chunk, 0);
	while (a->len && chunk->min <= nb_max)
	{
		if (!sort_in_chunk(a, chunk))
		{
			chunk->min += chunk->cut;
			chunk->max += chunk->cut;
		}
		else
		{
			sort_stack(a, b);
			push_b(a, b);
		}
	}
	while (b->len)
	{
		sort_stack(a, b);
		push_a(a, b);
	}
}

void	only_five_hundred(t_stack *a, t_stack *b, t_chunk *chunk)
{
	int	nb_max;

	find_max_min(a);
	nb_max = chunk_value(a, chunk, 1);
	while (a->len && chunk->min <= nb_max)
	{
		if (!sort_in_chunk(a, chunk))
		{
			chunk->min += chunk->cut;
			chunk->max += chunk->cut;
		}
		else
		{
			push_b(a, b);
			sort_stack(a, b);
		}
	}
	while (b->len)
	{
		sort_stack(a, b);
		push_a(a, b);
	}
}

