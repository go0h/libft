/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 16:10:50 by astripeb          #+#    #+#             */
/*   Updated: 2019/06/15 16:15:10 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				ft_printf(const char *frm, ...)
{
	va_list			ap;
	t_modific		*mod;
	int				n;

	mod = NULL;
	mod = new_modific(mod, 1);
	va_start(ap, frm);
	n = 0;
	while (*frm)
	{
		n += *frm != '%' && *frm != '{' ? ft_putchar_fd(*frm, mod->fd) : 0;
		frm += *frm == '{' ? set_color(frm, &n, 1) : 0;
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

int				pr_sp(va_list ap, t_modific *mod, char spec)
{
	int			n;

	n = 0;
	if (spec == 'c' || spec == 'C')
		n = print_char(va_arg(ap, int), mod, spec);
	else if (spec == 's' || spec == 'S')
		n = print_str(va_arg(ap, char *), mod, spec);
	else if (spec == 'p')
		n = print_pointer(va_arg(ap, long long int), mod);
	else if (spec == 'd' || spec == 'i' || spec == 'D')
		n = print_num_s(va_arg(ap, intmax_t), mod, spec);
	else if (spec == 'u' || spec == 'U')
		n = print_num_u(va_arg(ap, uintmax_t), mod, spec);
	else if (spec == 'x' || spec == 'X' || spec == 'o' || spec == 'O')
		n = print_not_dec(va_arg(ap, unsigned long long int), mod, spec);
	else if (spec == 'b')
		n = print_binary(va_arg(ap, int), mod);
	else if (spec == 'f' || spec == 'F')
		n = print_double(ap, mod, spec);
	else if (spec == 'e' || spec == 'E')
		n = print_scientific(ap, mod, spec);
	return (n);
}

int				pr_non_sp(t_modific *mod, char c)
{
	if (c == '\0')
		return (0);
	if (!mod->align)
		print_filler(mod->width - 1, mod->zero ? '0' : ' ', mod->fd);
	ft_putchar_fd(c, mod->fd);
	mod->align ? print_filler(mod->width - 1, ' ', mod->fd) : 0;
	return (ft_max(mod->width, 1));
}
