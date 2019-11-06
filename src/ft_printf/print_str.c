/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 17:16:10 by pcredibl          #+#    #+#             */
/*   Updated: 2019/06/18 14:54:24 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		get_fill(char *s, char spec, t_modific *mod, int *len)
{
	int i;
	int *is;

	*len = mod->sp && !mod->precision ? 0 : *len;
	if (spec == 's' && mod->type != 3)
		return (mod->width - *len);
	is = (int*)s;
	if (mod->precision)
	{
		i = ft_lenwchar(*is);
		while (*is)
		{
			++is;
			if (mod->precision < (i + ft_lenwchar(*is)))
				break ;
			i += ft_lenwchar(*is);
		}
	}
	return (mod->width - (mod->precision ? i : *len));
}

int				print_str(char *str, t_modific *mod, char spec)
{
	int		len_str;
	int		n;

	n = 0;
	if (spec == 's' && mod->type != 3)
		len_str = !str ? 6 : ft_strlen(str);
	else
		len_str = !str ? 6 : ft_lstrlen((int*)str);
	if (mod->precision)
	{
		mod->precision = mod->precision < 0 ? 0 : mod->precision;
		len_str = mod->precision > len_str ? len_str : mod->precision;
	}
	if (!mod->align)
		n += print_filler(get_fill(str, spec, mod, &len_str), mod->zero ? '0' :\
			' ', mod->fd);
	if (!str)
		write(mod->fd, "(null)", len_str);
	else if (*str && mod->type != 3 && spec != 'S')
		write(mod->fd, str, len_str);
	else if (mod->type == 3 || spec == 'S')
		n += ft_putnstr_utf8_fd((int*)str, mod->fd, len_str) - len_str;
	if (mod->align)
		n += print_filler(get_fill(str, spec, mod, &len_str), ' ', mod->fd);
	return (len_str + n);
}
