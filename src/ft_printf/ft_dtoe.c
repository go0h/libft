/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 20:46:55 by astripeb          #+#    #+#             */
/*   Updated: 2019/06/18 14:52:26 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char		*ft_e_part(long int mantissa, int *exp, char *ofset)
{
	long int	int_part[MAX_LEN];
	long int	temp[MAX_LEN];
	char		*str;
	char		flag;

	ft_bzero_long(int_part, MAX_LEN);
	flag = *exp < 4 ? 1 : 0;
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
	str = flag ? ft_strjoin_f(laitoe(int_part), ".") : laitoe(int_part);
	return (str);
}

static char		*ft_add_exp(long double dbl, int exp)
{
	char		*sci;
	char		*temp;
	t_ex_double u_d;

	u_d.dbl = dbl;
	if (!(sci = ft_strjoin("e", (u_d.t_fd.exponent - 16383 >= 0)
					|| dbl == 0 ? "+" : "-")))
		exit(MALLOC_FAILURE);
	if (!(temp = ft_itoa(exp)))
		exit(MALLOC_FAILURE);
	if (ft_strlen(temp) == 1)
	{
		if (!(temp = ft_strjoin_s("0", temp)))
			exit(MALLOC_FAILURE);
	}
	if (!(sci = ft_strjoin_f(sci, temp)))
		exit(MALLOC_FAILURE);
	free(temp);
	return (sci);
}

static int		ft_get_exp(long double dbl, int precision)
{
	int			i;
	long double	ten;

	dbl < 0 ? dbl *= -1 : 0;
	ten = dbl > 10.0L ? 10.0L : 1.0L;
	i = precision < 0 && dbl < 1.0L ? -1 : 0;
	if (dbl > 10.0L)
	{
		while (dbl > ten)
		{
			ten *= 10.0L;
			++i;
		}
		i += precision < 0 && (ten - dbl) < (ten / 10.0L) / 2.0L ? 1 : 0;
	}
	else if (dbl != 0)
	{
		while (dbl < ten)
		{
			ten /= 10.0L;
			++i;
		}
	}
	return (i);
}

int				ft_round_e(char **str, long double d, t_modific *mod)
{
	char		*dbl;
	char		*sci;
	int			exp;

	dbl = *str;
	ft_round_dbl(&dbl, mod->precision);
	if (dbl[0] != '-' && dbl[1] != '.')
		dbl[1] = '\0';
	else if (dbl[0] == '-' && dbl[2] != '.')
		dbl[2] = '\0';
	(mod->hash && mod->precision < 0) ? dbl = ft_strjoin_f(dbl, ".") : 0;
	exp = ft_get_exp(d, mod->precision);
	sci = ft_add_exp(d, exp);
	*str = ft_strjoin_f(dbl, sci);
	free(sci);
	return (ft_strlen(*str));
}

char			*ft_dtoe(long double dbl, int precision)
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
	int_part = exp >= 0 ? ft_e_part(u_d.t_fd.mantissa, &exp, &ofset) : NULL;
	if (!int_part)
		int_part = ft_dec_part(u_d.t_fd.mantissa, ft_abs(exp), &ofset, 0);
	else if (precision && ofset)
	{
		dec_part = ft_dec_part(u_d.t_fd.mantissa, ft_abs(exp), &ofset, 1);
		int_part = ft_strjoin_f(int_part, dec_part);
		free(dec_part);
	}
	if (u_d.t_fd.sign && !(int_part = ft_strjoin_s("-", int_part)))
		exit(MALLOC_FAILURE);
	return (int_part);
}
