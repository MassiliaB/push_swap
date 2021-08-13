/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 16:35:00 by user42            #+#    #+#             */
/*   Updated: 2020/11/19 13:20:02 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

int				ft_strlen(char *str);
int				ft_strcmp(char *s1, char *s2);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_atoi(char *str);
int				ft_isdigit(int c);

#endif
