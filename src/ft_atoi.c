/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:46:43 by astripeb          #+#    #+#             */
/*   Updated: 2019/08/28 12:29:21 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_atoi(const char *str)
{
	long int		nb;
	int				flag;

	nb = 0;
	while ((*str > 8 && *str < 14) || *str == 32)
		++str;
	flag = (*str == '+' || *str == '-') ? (44 - *str++) : 1;
	while (*str > 47 && *str < 58)
	{
		if ((nb > 214748363 && *str > '7' && flag == 1) ||\
				nb > 214748364)
			return (-1);
		else if ((nb > 214748363 && *str > '8' && flag == -1) ||\
				nb > 214748364)
			return (0);
		nb = nb * 10 + (*str++ - '0');
	}
	return (nb * flag);
}

int					ft_atoi_ps(const char *str)
{
	long int		nb;
	int				flag;

	nb = 0;
	while ((*str > 8 && *str < 14) || *str == 32)
		++str;
	flag = *str == '-' ? -1 : 1;
	*str == '-' ? str++ : 0;
	while (*str > 47 && *str < 58)
	{
		if ((nb > 214748363 && ((*str > '7' && flag == 1) ||\
			(*str > '8' && flag == -1))) || nb > 214748364)
			exit(write(2, "Error\n", 7));
		nb = nb * 10 + (*str++ - '0');
	}
	return (nb * flag);
}
