/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula </var/mail/masboula>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 17:31:01 by masboula          #+#    #+#             */
/*   Updated: 2021/08/12 17:31:50 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libps.h"

int	swap_a(s_stack *a)
{
	int	temp;

	if (!a || !a->tab || a->len < 2)
		return (0);
	temp = a->tab[0];
	a->tab[0] = a->tab[1];
	a->tab[1] = temp;
	write(1, "sa\n", 3);
	print_stack(a);
	a->nbr_mooves += 1;
	return (1);
}

int	swap_b(s_stack *a, s_stack *b)
{
	int	temp;

	if (!b || !b->tab || b->len < 2)
		return (0);
	temp = b->tab[0];
	b->tab[0] = b->tab[1];
	b->tab[1] = temp;
	write(1, "sb\n", 3);
	print_stack(a);
	a->nbr_mooves += 1;
	return (1);
}

int	swap_both(s_stack *a, s_stack *b)
{
	swap_a(a);
	swap_b(a, b);
	write(1, "ss\n", 3);
	a->nbr_mooves += 1;
	print_stack(a);
	return (1);
}
