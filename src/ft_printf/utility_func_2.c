/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_func_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 19:42:20 by astripeb          #+#    #+#             */
/*   Updated: 2019/06/14 19:42:38 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		add_dig_s(long long int nbr, int base, char *stack, int k)
{
	*stack = ft_abs(nbr % base) > 9 ? (ft_abs(nbr % base % 10) + 'a' - k)\
			: (ft_abs(nbr % base) + '0');
	if (nbr / base != 0 && stack - 1)
		add_dig_s(nbr / base, base, stack - 1, k);
}

void		add_dig_u(unsigned long long int nbr, int base, char *stack, int k)
{
	*stack = nbr % base > 9 ? (nbr % base % 10 + 'a' - k) : (nbr % base + '0');
	if (nbr / base != 0 && stack - 1)
		add_dig_u(nbr / base, base, stack - 1, k);
}
