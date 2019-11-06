/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 14:49:53 by pcredibl          #+#    #+#             */
/*   Updated: 2019/06/15 16:21:45 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				ft_fprintf(int fd, const char *frm, ...)
{
	va_list		ap;
	t_modific	*mod;
	int			n;

	mod = NULL;
	mod = new_modific(mod, fd);
	va_start(ap, frm);
	n = 0;
	while (*frm)
	{
		n += *frm != '%' && *frm != '{' ? ft_putchar_fd(*frm, mod->fd) : 0;
		if (*(frm + 1) != '\0')
			if (*frm == '%')
			{
				*++frm == 'n' ? count_print(va_arg(ap, long long int), n) : 0;
				frm += parsing_modific(frm, mod, ap);
				n += *frm && isspec(*++frm) ? pr_sp(ap, mod, *frm) :\
					pr_non_sp(mod, *frm);
			}
		frm++;
	}
	free(mod);
	va_end(ap);
	return (n);
}
