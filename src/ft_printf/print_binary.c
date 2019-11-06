/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_binary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 19:02:57 by pcredibl          #+#    #+#             */
/*   Updated: 2019/06/06 16:34:50 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		print_binary(unsigned long long num, t_modific *mod)
{
	int			i;

	i = 0;
	i += !mod->align ? print_filler((mod->width -\
				ft_max(mod->precision, numlen(num, 2))) *\
			(!mod->zero || mod->precision), ' ', mod->fd) : 0;
	i += !mod->align && mod->zero && !mod->precision ?\
			print_filler(mod->width - numlen(num, 2), '0', mod->fd) : 0;
	i += mod->precision ? print_filler(mod->precision - numlen(num, 2),\
			'0', mod->fd) : 0;
	i += mod->precision < 0 && num == 0 ? 0 : ft_putnbr_b(num, mod);
	i += mod->align ? print_filler(mod->width -\
			ft_max(mod->precision, numlen(num, 2)), ' ', mod->fd) : 0;
	return (i);
}
