/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_arithmetic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 21:44:31 by astripeb          #+#    #+#             */
/*   Updated: 2019/06/06 15:14:21 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			ft_add(long int a[], long int b[])
{
	short		i;
	long int	y;

	i = 0;
	y = 0;
	while (i < MAX_LEN)
	{
		y = a[i] + b[i] + y;
		a[i] = y % BASE;
		y /= BASE;
		++i;
	}
}

void			ft_mul_s(long int a[], long int b, short len)
{
	short		i;
	short		j;
	long int	y;

	j = size_long(a, len) + 1;
	i = 0;
	y = 0;
	while (i <= j)
	{
		y = a[i] * b + y;
		a[i] = y % BASE;
		y /= BASE;
		++i;
	}
}

void			ft_pow_l(long int a[], int exp, int base, short len)
{
	ft_bzero_long(a, len);
	a[0] = 1;
	while (exp--)
	{
		ft_mul_s(a, base, len);
	}
}

int				size_long(long int a[], short len)
{
	short		i;

	i = len - 1;
	while (!a[i] && i)
		--i;
	return (a[i] ? i : -1);
}

void			ft_bzero_long(long int a[], short len)
{
	short		i;

	i = 0;
	while (i < len)
	{
		a[i++] = 0;
	}
}
