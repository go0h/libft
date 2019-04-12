/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:46:43 by astripeb          #+#    #+#             */
/*   Updated: 2019/04/12 21:25:08 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int					ft_atoi(const char *str)
{
	int			nb;
	int			flag;
	long long	lnbr;

	lnbr = 0;
	nb = 0;
	flag = 1;
	while ((*str > 8 && *str < 14) || *str == 32)
		++str;
	if (*str == '-' || *str == '+')
		flag = 44 - *str++;
	while (*str > 47 && *str < 58)
	{
		lnbr = lnbr * 10 + (*str - 48);
		nb = nb * 10 + (*str++ - 48);
	}
	if (lnbr < 0 && flag == -1)
		return (0);
	else if (lnbr < 0 && flag == 1)
		return (-1);
	return (nb * flag);
}
