/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 20:27:43 by astripeb          #+#    #+#             */
/*   Updated: 2019/06/18 11:58:56 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				ft_ismodific(char c)
{
	if (c != ' ' && c != '#' && c != '\'' && c != '+' && c != '-' &&
			c != '0' && c != 'l' && c != 'L' && c != 'h' && c != 'j' &&
			c != 'z' && c != '*')
		return (0);
	return (1);
}

int				isspec(char c)
{
	if (c != 'c' && c != 's' && c != 'p' && c != 'd' && c != 'i' &&
			c != 'o' && c != 'u' && c != 'x' && c != 'X' && c != 'f' &&
			c != 'b' && c != 'U' && c != 'e' && c != 'S' && c != 'C' &&
			c != 'D' && c != 'O' && c != 'F' && c != 'E')
		return (0);
	return (1);
}

t_modific		*new_modific(t_modific *mod, int fd)
{
	if (!mod)
	{
		if (!(mod = (t_modific*)malloc(sizeof(t_modific))))
			exit(MALLOC_FAILURE);
		mod->fd = fd;
	}
	mod->zero = 0;
	mod->width = 0;
	mod->precision = 0;
	mod->plus = 0;
	mod->align = 0;
	mod->hash = 0;
	mod->space = 0;
	mod->type = 0;
	mod->sp = 0;
	return (mod);
}

static void		parsing_types(const char *str, t_modific *mod)
{
	while (*str == 'h' || *str == 'l' || *str == 'L' ||
			*str == 'j' || *str == 'z')
	{
		*str == 'h' && mod->type == 1 ? mod->type = 2 : 0;
		*str == 'h' && !mod->type ? mod->type = 1 : 0;
		*str == 'l' && mod->type == 3 ? mod->type = 4 : 0;
		*str == 'l' && !mod->type ? mod->type = 3 : 0;
		*str == 'L' && !mod->type ? mod->type = 5 : 0;
		*str == 'z' && !mod->type ? mod->type = 6 : 0;
		*str == 'j' && !mod->type ? mod->type = 7 : 0;
		str++;
	}
}

int				parsing_modific(const char *str, t_modific *mod, va_list ap)
{
	int			c;

	c = ft_strlen_s(str) - 1;
	mod = new_modific(mod, mod->fd);
	while (ft_ismodific(*str))
	{
		*str == ' ' ? mod->space = 1 : 0;
		*str == '#' ? mod->hash = 1 : 0;
		*str == '+' ? mod->plus = 1 : 0;
		*str == '-' ? mod->align = 1 : 0;
		*str == '0' ? mod->zero = 1 : 0;
		*str == '*' ? spec_star(va_arg(ap, int), mod) : 0;
		parsing_types(str++, mod);
	}
	str += ft_atoi(str) == 0 ? 0 : numlen((mod->width = ft_atoi(str)), 10);
	str += *str == '*' ? spec_star(va_arg(ap, int), mod) : 0;
	if (*str == '.')
		str += set_precision(ap, mod, str + 1);
	if (*str == '*' && ft_isdigit(*(str - 1)))
		str += spec_star(va_arg(ap, int), mod);
	parsing_types(str, mod);
	return (c);
}
