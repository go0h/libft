/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_scientific.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 21:26:33 by astripeb          #+#    #+#             */
/*   Updated: 2019/06/18 14:53:35 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	print_fil_e(char *str, t_modific *mod, int flag)
{
	int			n;
	int			len;
	int			c;

	len = ft_strlen(str);
	n = 0;
	c = (mod->zero && flag) ? '0' : 32;
	mod->width -= (mod->plus && *str != 45);
	n += mod->width > len ? print_filler(mod->width - len, c, mod->fd) : 0;
	n += (mod->plus && *str != 45 && flag) ? ft_putchar(43) : 0;
	n += (!mod->plus && *str != 45 && flag && mod->space) ? ft_putchar(32) : 0;
	return (n);
}

int			print_scientific(va_list ap, t_modific *mod, char spec)
{
	char		*str;
	int			n;
	long double dbl;

	mod->precision = !mod->precision ? 6 : mod->precision;
	dbl = mod->type == 5 ? va_arg(ap, long double) : va_arg(ap, double);
	str = ft_dtoe(dbl, mod->precision);
	if (!ft_strstr(str, "inf") && !ft_strstr(str, "nan"))
		ft_round_e(&str, dbl, mod);
	spec == 'E' ? ft_to_uppercase(str) : 0;
	n = ft_strlen(str);
	n += !mod->align ? print_fil_e(str, mod, 1) : 0;
	write(mod->fd, str, ft_strlen(str));
	n += mod->align ? print_fil_e(str, mod, 0) : 0;
	free(str);
	return (n);
}
