/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 16:23:43 by astripeb          #+#    #+#             */
/*   Updated: 2019/06/14 19:29:12 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_putnbr_s(long long int n, t_modific *mod)
{
	int		i;
	char	stack[65];

	i = numlen(n, 10) - 1;
	ft_bzero((void*)stack, 65);
	add_dig_s(n, 10, &stack[i], 0);
	return (ft_putstr_fd(stack, mod->fd));
}

int			ft_putnbr_u(unsigned long long n, t_modific *mod)
{
	int		i;
	char	stack[65];

	i = numlen_u(n, 10) - 1;
	ft_bzero((void*)stack, 65);
	add_dig_u(n, 10, &stack[i], 0);
	return (ft_putstr_fd(stack, mod->fd));
}

int			ft_putnbr_b(unsigned long long n, t_modific *mod)
{
	int		i;
	char	stack[65];

	i = numlen_u(n, 2) - 1;
	ft_bzero((void*)stack, 65);
	add_dig_u(n, 2, &stack[i], 0);
	return (ft_putstr_fd(stack, mod->fd));
}

int			print_nbr(unsigned long long int nbr, int base, char spec, int fd)
{
	int		k;
	char	stack[65];
	int		i;

	i = numlen_u(nbr, base) - 1;
	ft_bzero((void*)stack, 65);
	k = spec == 'X' || spec == 'O' ? 32 : 0;
	add_dig_u(nbr, base, &stack[i], k);
	return (ft_putstr_fd(stack, fd));
}
