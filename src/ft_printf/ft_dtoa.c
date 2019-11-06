/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 20:46:55 by astripeb          #+#    #+#             */
/*   Updated: 2019/06/18 14:50:43 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char			*ft_get_zeros_ap(long int mant, char ofset, int exp)
{
	int				i;
	long int		log2;
	char			*part;

	log2 = LOG2;
	i = 0;
	if (exp != 1)
		return (NULL);
	while (ofset >= 0 && !((mant >> ofset) & 1L))
	{
		++i;
		--ofset;
	}
	if (i == 0)
		return (NULL);
	i = i * *(double*)&log2;
	if (!(part = ft_strnew(i)))
		exit(MALLOC_FAILURE);
	ft_memset((void*)part, '0', i);
	return (part);
}

static char			*ft_get_zeros(int exp)
{
	int				i;
	long int		log2;
	char			*part;

	log2 = LOG2;
	i = 0;
	exp = ft_abs(exp);
	i = exp * *(double*)&log2 + 2;
	if (!(part = ft_strnew(i)))
		exit(MALLOC_FAILURE);
	ft_memset((void*)part, '0', i);
	part[1] = '.';
	return (part);
}

char				*ft_dec_part(long int mant, int exp, char *ofset, char flag)
{
	long int		dec_part[MAX_LEN];
	long int		temp[MAX_LEN];
	char			*str;
	char			*zeros;

	zeros = ft_get_zeros_ap(mant, *ofset, exp);
	ft_bzero_long(dec_part, MAX_LEN);
	while (*ofset >= 0)
	{
		if ((mant >> *ofset) & 1L)
		{
			ft_pow_l(temp, exp, 5, MAX_LEN);
			ft_add(dec_part, temp);
		}
		ft_mul_s(dec_part, 10, MAX_LEN);
		exp != 16383 ? ++exp : 0;
		--(*ofset);
	}
	str = flag ? laitoa(dec_part) : laitoe(dec_part);
	if (!zeros)
		return (str);
	if (!(str = ft_strjoin_s(zeros, str)))
		exit(MALLOC_FAILURE);
	free(zeros);
	return (str);
}

static char			*ft_int_part(long int mantissa, int *exp, char *ofset)
{
	long int		int_part[MAX_LEN];
	long int		temp[MAX_LEN];
	char			*str;

	ft_bzero_long(int_part, MAX_LEN);
	while (*exp >= 0)
	{
		if ((mantissa >> *ofset) & 1L)
		{
			ft_pow_l(temp, *exp, 2, MAX_LEN);
			ft_add(int_part, temp);
		}
		--(*ofset);
		--(*exp);
		if (*ofset < 0)
			break ;
	}
	str = laitoa(int_part);
	if (*ofset)
	{
		if (!(str = ft_strjoin_f(str, ".")))
			exit(MALLOC_FAILURE);
	}
	return (str);
}

char				*ft_dtoa(long double dbl, int precision)
{
	char			*int_part;
	char			*dec_part;
	t_ex_double		u_d;
	char			ofset;
	int				exp;

	u_d.dbl = dbl;
	ofset = 63;
	if ((int_part = ft_isspecdouble(u_d)))
		return (int_part);
	exp = u_d.t_fd.exponent - 16383;
	if (exp >= 0)
		int_part = ft_int_part(u_d.t_fd.mantissa, &exp, &ofset);
	else
		int_part = ft_get_zeros(exp);
	if (precision && ofset)
	{
		dec_part = ft_dec_part(u_d.t_fd.mantissa, ft_abs(exp), &ofset, 1);
		int_part = ft_strjoin_f(int_part, dec_part);
		free(dec_part);
	}
	if (u_d.t_fd.sign && !(int_part = ft_strjoin_s("-", int_part)))
		exit(MALLOC_FAILURE);
	return (int_part);
}
