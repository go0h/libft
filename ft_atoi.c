/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:46:43 by astripeb          #+#    #+#             */
/*   Updated: 2019/04/23 23:21:59 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		nb = nb * 10 + (*str++ - '0');
		if (flag == 1 && nb != nb * 10 / 10)
			return (-1);
		else if (flag == -1 && nb != nb * 10 / 10)
			return (0);
	}
	return (nb * flag);
}
