/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 18:25:50 by astripeb          #+#    #+#             */
/*   Updated: 2019/06/14 20:17:50 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		print_pointer(long long int adr, t_modific *mod)
{
	int n;

	n = 0;
	if (!mod->align && !mod->zero)
		n += print_filler(mod->width - ft_max(mod->precision, adr == 0 &&\
				mod->precision < 0 ? 0 : numlen(adr, 16)) - 2, ' ', mod->fd);
	n += print_hex_prefix(1, mod->fd);
	n += (mod->zero && !mod->align) || mod->precision > 0 ?\
		print_filler(ft_max(mod->width - n - numlen(adr, 16),\
				mod->precision - numlen(adr, 16)), '0', mod->fd) : 0;
	n += adr != 0 || mod->precision > -1 ? print_nbr(adr, 16, 0, mod->fd) : 0;
	if (mod->align)
		n += print_filler(mod->width - ft_max(mod->precision, adr == 0 &&\
				mod->precision < 0 ? 0 : numlen(adr, 16)) - 2, ' ', mod->fd);
	return (n);
}
