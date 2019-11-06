/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 13:03:38 by pcredibl          #+#    #+#             */
/*   Updated: 2019/10/18 20:33:10 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		set_start_value(char spec, int *base,\
		unsigned long long int num, t_modific *mod)
{
	*base = spec == 'o' || spec == 'O' ? 8 : 16;
	mod->hash = mod->hash;
	num = num + 1 - 1;
	mod->hash && *base == 16 && num != 0 ? (mod->width = mod->width - 2) : 0;
	mod->hash && *base == 8 ? mod->width-- : 0;
	mod->hash && *base == 8 && mod->precision > 0 ? mod->precision-- : 0;
}

int				print_ox_num(unsigned long long num, t_modific *mod, char spec)
{
	int			base;
	int			i;

	i = 0;
	base = spec == 'o' || spec == 'O' ? 8 : 16;
	i += (mod->hash && mod->precision > 0 && base == 8) || num ||\
			(!mod->hash && !(mod->precision < 0 && num == 0)) ?\
			print_nbr(num, base, spec, mod->fd) : 0;
	return (i);
}

int				print_not_dec(unsigned long long int num,
		t_modific *mod, char spec)
{
	int			base;
	int			i;
	int			num_len;

	set_start_value(spec, &base, num, mod);
	mod->type == 1 && spec != 'O' ? num = (unsigned short)num : 0;
	mod->type == 2 && spec != 'O' ? num = (unsigned char)num : 0;
	mod->type == 3 || spec == 'O' ? num = (unsigned long)num : 0;
	mod->type == 0 && spec != 'O' ? num = (unsigned int)num : 0;
	i = 0;
	num_len = num == 0 ? 0 : numlen(num, base);
	i += !mod->align && !mod->zero ? print_filler(mod->width -\
			ft_max(mod->precision, num_len), ' ', mod->fd) : 0;
	if (mod->hash && mod->precision < 0 && base == 16 && num == 0)
		return (i);
	i += mod->hash ? ft_putchar_fd('0', mod->fd) : 0;
	i += mod->hash && base == 16 && num != 0 ? ft_putchar_fd(spec, mod->fd) : 0;
	i += !mod->align && mod->zero ? print_filler(mod->width -\
			ft_max(mod->precision, num_len), '0', mod->fd) : 0;
	i += mod->precision > 0 ? print_filler(mod->precision - numlen(num, base),\
			'0', mod->fd) : 0;
	i += print_ox_num(num, mod, spec);
	i += mod->align ? print_filler(mod->width -\
			ft_max(mod->precision, num_len), ' ', mod->fd) : 0;
	return (i);
}

int				print_num_s(intmax_t num, t_modific *mod, char spec)
{
	int			i;

	i = 0;
	mod->type == 0 && (spec == 'd' || spec == 'i') ? num = (int)num : 0;
	mod->type == 1 && (spec == 'd' || spec == 'i') ? num = (short)num : 0;
	mod->type == 2 && (spec == 'd' || spec == 'i') ? num = (char)num : 0;
	mod->type == 3 || spec == 'D' ? num = (long)num : 0;
	mod->type == 4 && (spec == 'd' || spec == 'i') ? num = (long long)num : 0;
	mod->type == 6 && (spec == 'd' || spec == 'i') ? num = (size_t)num : 0;
	mod->space && !mod->plus && num >= 0 ? mod->width-- : 0;
	i += mod->space && num >= 0 && !mod->plus ? ft_putchar_fd(' ', mod->fd) : 0;
	num < 0 || mod->plus ? mod->width-- : 0;
	i += !mod->align ? print_filler((mod->width - ft_max(mod->precision,\
		numlen(num, 10)) * (num || mod->precision >= 0)) *\
			(!mod->zero || mod->precision), ' ', mod->fd) : 0;
	i += num < 0 ? ft_putchar_fd('-', mod->fd) : 0;
	i += mod->plus && num >= 0 ? ft_putchar_fd('+', mod->fd) : 0;
	i += !mod->align && mod->zero && !mod->precision ?
		print_filler(mod->width - numlen(num, 10), '0', mod->fd) : 0;
	i += mod->precision ? print_filler(mod->precision -\
		numlen(num, 10), '0', mod->fd) : 0;
	i += (mod->precision < 0) && (num == 0) ? 0 : ft_putnbr_s(num, mod);
	i += mod->align ? print_filler(mod->width - (ft_max(mod->precision,\
					numlen(num, 10))), ' ', mod->fd) : 0;
	return (i);
}

int				print_num_u(uintmax_t num, t_modific *mod, char spec)
{
	int			i;

	i = 0;
	mod->type == 0 && spec == 'u' ? num = (unsigned int)num : 0;
	mod->type == 1 && spec == 'u' ? num = (unsigned short)num : 0;
	mod->type == 2 && spec == 'u' ? num = (unsigned char)num : 0;
	mod->type == 3 || spec == 'U' ? num = (unsigned long)num : 0;
	mod->type == 4 && spec == 'u' ? num = (unsigned long long)num : 0;
	mod->type == 6 && spec == 'u' ? num = (size_t)num : 0;
	i += !mod->align ? print_filler((mod->width - ft_max(mod->precision,\
			numlen(num, 10))) * (!mod->zero || mod->precision),\
			' ', mod->fd) : 0;
	i += !mod->align && mod->zero && !mod->precision ?\
		print_filler(mod->width - numlen(num, 10), '0', mod->fd) : 0;
	i += mod->precision ? print_filler(mod->precision -\
			numlen(num, 10), '0', mod->fd) : 0;
	i += mod->precision < 0 && num == 0 ? 0 : ft_putnbr_u(num, mod);
	i += mod->align ? print_filler(mod->width -\
			ft_max(mod->precision, numlen(num, 10)), ' ', mod->fd) : 0;
	return (i);
}
