/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula </var/mail/masboula>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 17:30:44 by masboula          #+#    #+#             */
/*   Updated: 2021/08/12 17:30:46 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libps.h"

int	reverse_ra(t_stack *a)
{
	int		i;
	int		temp;

	if (!a || !a->tab || a->len < 2)
		return (0);
	i = a->len - 1;
	temp = a->tab[i];
	while (i > 0)
	{
		a->tab[i] = a->tab[i - 1];
		i--;
	}
	a->tab[i] = temp;
	write(1, "rra\n", 4);
	a->nbr_mooves += 1;
	return (1);
}

int	reverse_rb(t_stack *a, t_stack *b)
{
	int		i;
	int		temp;

	if (!b || !b->tab || b->len < 2)
		return (0);
	i = b->len - 1;
	temp = b->tab[i];
	while (i > 0)
	{
		b->tab[i] = b->tab[i - 1];
		i--;
	}
	b->tab[i] = temp;
	write(1, "rrb\n", 4);
	a->nbr_mooves += 1;
	return (1);
}

int	reverse_rboth(t_stack *a, t_stack *b)
{
	reverse_ra(a);
	reverse_rb(a, b);
	write(1, "rrr\n", 4);
	a->nbr_mooves += 1;
	return (0);
}
