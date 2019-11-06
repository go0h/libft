/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 18:58:30 by astripeb          #+#    #+#             */
/*   Updated: 2019/06/14 19:48:36 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			numlen(long long int nbr, int base)
{
	int		i;

	i = 1;
	while (nbr / base != 0)
	{
		++i;
		nbr /= base;
	}
	return (i);
}

int			numlen_u(unsigned long long int nbr, int base)
{
	int		i;

	i = 1;
	while (nbr / base != 0)
	{
		++i;
		nbr /= base;
	}
	return (i);
}

int			print_hex_prefix(char x, int fd)
{
	return (ft_putstr_fd(x ? "0x" : "0X", fd));
}

int			print_filler(int len, char c, int fd)
{
	int		i;
	int		n;
	char	stack[256];

	len = len * (len > 0);
	n = 0;
	while (1)
	{
		i = 0;
		while (i < 255 && n < len)
		{
			stack[i] = c;
			++i;
			++n;
		}
		stack[i] = '\0';
		ft_putstr_fd(stack, fd);
		if (n == len)
			break ;
	}
	return (n);
}

int			ft_strlen_s(const char *str)
{
	int		i;

	i = 0;
	while (ft_ismodific(str[i]) || ft_isdigit(str[i]) || str[i] == '.')
		i++;
	return (i);
}
