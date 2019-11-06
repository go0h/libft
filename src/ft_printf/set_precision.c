/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 17:53:26 by pcredibl          #+#    #+#             */
/*   Updated: 2019/06/18 12:44:51 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	pass_zeroes(const char *str)
{
	int		len;

	len = 0;
	while (*str++ == '0')
		len++;
	return (len);
}

static int	ft_strlen_prec(const char *s)
{
	int	i;

	i = 0;
	while (ft_isdigit(s[i]))
		i++;
	return (i);
}

int			set_precision(va_list ap, t_modific *mod, const char *str)
{
	int		num;

	if (*str == '*')
	{
		num = va_arg(ap, int);
		mod->precision = num < 0 ? 0 : num;
		mod->sp = num == 0 ? 1 : 0;
		return (2);
	}
	if ((mod->precision = ft_atoi(str)))
		return (ft_strlen_prec(str) + 1);
	if (*str == '0')
	{
		mod->precision = -2;
		return (pass_zeroes(str) + 1);
	}
	mod->precision = -1;
	return (1);
}

int			spec_star(int num, t_modific *mod)
{
	mod->align = num < 0 ? 1 : mod->align;
	mod->width = num < 0 ? -1 * num : num;
	return (1);
}
