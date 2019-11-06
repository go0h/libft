/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 17:04:36 by astripeb          #+#    #+#             */
/*   Updated: 2019/06/12 10:57:21 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** Print char with flags '-' and '0'
*/

int	print_char(int c, t_modific *mod, char spec)
{
	int n;

	n = 0;
	if (!mod->align)
		n += print_filler(mod->width - 1, !mod->zero ? ' ' : '0', mod->fd);
	if (mod->type == 3 || spec == 'C')
		n += ft_putchar_utf8_fd(c, mod->fd);
	else
		n += ft_putchar_fd(c, mod->fd);
	if (mod->align)
		n += print_filler(mod->width - 1, ' ', mod->fd);
	return (n);
}
