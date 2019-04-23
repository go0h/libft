/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:42:02 by astripeb          #+#    #+#             */
/*   Updated: 2019/04/23 23:35:01 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

long int		ft_atol(const char *str)
{
	long int		nb;
	int				flag;

	nb = 0;
	while ((*str > 8 && *str < 14) || *str == 32)
		++str;
	flag = (*str == '+' || *str == '-') ? (44 - *str++) : 1;
	while (*str > 47 && *str < 58)
	{
		nb = nb * 10 + (*str++ - '0');
		if (flag == -1 && nb != nb * 10 / 10)
			return (LONG_MIN);
		else if (flag == 1 && nb != nb * 10 / 10)
			return (LONG_MAX);
	}
	return (nb * flag);
}
