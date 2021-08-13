/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 16:02:05 by user42            #+#    #+#             */
/*   Updated: 2020/11/17 16:25:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strlen2(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] == ' ')
		i++;
	j = ft_strlen(str);
	while (str[j - 1] == ' ' || str[j - 1] == '\n')
		j--;
	return (j - i);
}
